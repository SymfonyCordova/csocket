#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int n = 0, flag = 0;

void sys_err(const char *str){
	perror(str);
	exit(1);
}

void do_sig_child(int num){//回调函数都是内核调用的
	printf("I'm child %d\t%d\n", getpid(), n);
	n += 2;
	flag = 1;
	sleep(1);
}

void do_sig_parent(int num){
	printf("I'm parent %d\t%d\n", getpid(), n);
	n += 2;
	flag = 1;
	sleep(1);
}

int main(void){
	pid_t pid;
	struct sigaction act;

	pid = fork();
	if(pid == -1){//出错情况
		sys_err("fork error");
	}else if(pid > 0){//父进程
		n = 1;
		sleep(1);
		act.sa_handler = do_sig_parent;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		sigaction(SIGUSR2, &act, NULL); //注册自己的捕捉信号 父使用SIGUSR2信号
		
		do_sig_parent(0);
		while(1){
			/* wait for signal */
			if(flag == 1){ //父进程数数完成
				kill(pid, SIGUSR1);
				flag = 0;//标志已经给子进程发送完信号
			}
		}
	}else{ //子进程
		n = 2;
		act.sa_handler = do_sig_child;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		sigaction(SIGUSR1, &act, NULL); //父进程数数完成发送SIGUSR1给子进程
		
		while(1){
			if(flag == 1){
				kill(getppid(), SIGUSR2);
				flag = 0;   //已经给父进程发送完信号
			}
		}

	}
}
