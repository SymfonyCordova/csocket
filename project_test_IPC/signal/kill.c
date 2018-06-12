#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 5

int main(void){
	/*
	int ret = kill(getpid(), SIGKILL);
	if(ret == -1 ){
		perror("kill error");
		exit(1);
	}
	*/
	
	raise(SIGSEGV);	
	abort();
	
	int i, pid, q;

	for(i = 0; i < N; ++i){
		pid = fork();
		if(pid == 0){
			break;
		}else if(pid == -1){
			perror("fork error");
			exit(1);
		}
		
		if(i == 2){
			q = pid;
		}
	}

	if(i < N){
		while(1){
			printf("I'm child %d, getpid = %u\n", i, getpid());
			sleep(1);
		}
	}else{
		sleep(1);
		kill(pid, SIGKILL);
		while(1)
			wait(NULL);
	}
	
	return 0;
}
