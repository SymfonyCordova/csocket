#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
/*
	#include <signal.h>
	int sigaction(int signum, const struct sigaction *act,
                     struct sigaction *oldact);

struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);//暂时不用
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);//废弃
           };
*/

void docatch(int signo){
	printf("%d signal is catched\n", signo);//signo 是捕捉的信号
	sleep(10);
	printf("signal catched finished\n");
}

int main(void){
	struct sigaction act;
	act.sa_handler = docatch;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_flags = 0; //默认属性, 信号捕捉函数执行期间，自动屏蔽本信号。
	
	//信号捕捉
	int ret = sigaction(SIGINT, &act, NULL);
	if(ret == -1){
		perror("sigaction error");
		exit(1);
	}
	
	while(1);	
	
	return 0;
}
