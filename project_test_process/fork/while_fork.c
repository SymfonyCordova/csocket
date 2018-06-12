#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM 5

int main(void){
	printf("循环创建子进程开始\n");
	int i;
	for(i = 0; i < NUM; ++i){
		int pid = fork();
		if(pid == -1){
			perror("fork error");
			exit(1);
		}else if(pid == 0){
			break;
		}
	}
	
	if(i < 5){
		sleep(i);
		printf("I'm %dth child progress, pid = %u, ppid = %u\n", ++i, getpid(), getppid());
	}else{
		sleep(i);
		printf("I'm parent progress, pid = %u, ppid = %u\n", getpid(), getppid());
	}

	return 0;
}
