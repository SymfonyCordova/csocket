#include <unistd.h>
#include <signal.h>
#include <stdio.h>

/*
	sigsuspend和pause一样,但是他解决了pause竞态时许
	
	pause:当一个信号被捕捉并且这个信号捕捉函数返回,在这种情况下pause函数返回-1并且errno是要设置EINTR

	sigsuspend: always returns -1, with errno set to indicate the error (normally, EINTR).

*/

/*

struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);//暂时不考虑
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);//已废弃
           };

*/


void sig_alrm(int signo){//保证sigsuspend
	/*nothing to do*/
}

unsigned int mysleep(unsigned int nsecs){
	struct sigaction newact, oldact;
	sigset_t newmask, oldmask, suspmask;
	unsigned int unslept;
	
	newact.sa_handler = sig_alrm;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;	
	sigaction(SIGALRM, &newact, &oldact); //1.注册信号捕捉函数

	//2.设置阻塞信号集让CPU内核不去处理SIGALRM信号,阻塞SIGALRM信号
	//保证CPU内核不要去处理到,留给sigsuspend获得信号
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGALRM);
	sigprocmask(SIG_BLOCK, &newmask, &oldmask);
	
	
	alarm(nsecs); //nsecs秒后发送SIGARM信号
	
	//构造一个调用的sigsuspend临时有效的阻塞信号集
	//在临时阻塞信号集里解除SIGALRM阻塞
	suspmask = oldmask;
	sigdelset(&suspmask, SIGALRM); //这里为什么会再此把SIGALRM没有被屏蔽,因为你不能保证原来的oldmask里面的SIGALRM没被屏蔽

	//sigsuspend调用期间,采用临时阻塞信号集suspmask替换原有阻塞信号集
	//这个信号集中不包括SIGALRM信号,同时挂起等待
	//当sigsuspend被信号唤醒返回时,恢复原有的阻塞信号集
	sigsuspend(&suspmask); //挂起等待接收信号, 唤醒该函数,执行后面的代码 原子操作不可再分的操作i

	//取消闹钟
	unslept = alarm(0);

	//恢复SIGALRM原有的处理动作, 呼应前面的注释1
	sigaction(SIGALRM, &oldact, NULL);

	//解除对SIGALRM的阻塞,呼应前面的注释2
	sigprocmask(SIG_SETMASK, &oldmask, NULL);
	
	return unslept;
}



int main(void){
		
	while(1){
		mysleep(3);
		printf("----\n");
	}
	return 0;
}
