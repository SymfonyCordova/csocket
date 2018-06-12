#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
/*
	当一个信号被捕捉并且这个信号捕捉函数有返回,在这种情况下pause函数返回-1并且erron是要设置EINTR
*/

void catch_sigalarm(int signo){//捕捉函数的目的是为了让pause中断唤醒
	;//啥事情都不干
}

/*
	 struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);//暂时不考虑
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);//已废弃
           };
*/

unsigned int mysleep(unsigned int seconds){
	struct sigaction act, oldact;
	
	act.sa_handler = catch_sigalarm;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	//注册捕捉函数 signal sigaction两种注册函数
	int ret = sigaction(SIGALRM, &act, &oldact);
	if(ret == -1){
		perror("sigaction error");
		exit(1);
	}

	alarm(seconds); //先alarm否则没用了因为pause一上来就挂起,下面代码将不会执行
	//------------------------------有可能失去CPU
	//------------------------------这是一个比较极端的事情,但确实存在,在UNIX服务器7*24小时不关机
	//程序在运行时等了好长时间信号已经发送完毕,按照信号的特性,此时CPU内核不会执行pause，而是先处理掉信号,调用完信号的捕捉函数
	//之后运行pause,但是pause再也收不到信号了然后一直等信号,程序就永远等待在这里,永久阻塞在这里
	ret = pause(); //主动挂起 等信号
	if(ret == -1 && errno == EINTR){
		printf("pause sucess\n");
	}

	//这两步保证程序的健壮性	
	ret = alarm(0);//将闹钟清0
	sigaction(SIGALRM, &oldact, NULL); //恢复SIGALRM信号旧有的处理方式

	return ret;
}

int main(void){
	while(1){
		mysleep(5);
		printf("----\n");
	}	
	return 0;
}
