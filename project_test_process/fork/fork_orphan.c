#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	int pid = fork();
	if(pid == -1){
		perror("fork error");
		exit(1);
	}else if(pid == 0){	
		printf("我是子进程, pid=%u, ppid=%u\n", getpid(), getppid());
		sleep(3);
		printf("我是子进程, pid=%u, ppid=%u\n", getpid(), getppid());
	}else{
		sleep(1);
		printf("我是父进程, pid=%u, ppid=%u\n", getpid(), getppid());
	}

	return 0;
}
