#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int var = 34;

int main(void){
	printf("全局程序,开始没有创建子进程!\n");
	int pid = fork();
	if(pid == -1){
		perror("fork error");
		exit(1);
	}else if(pid == 0){
		var = 100;
		printf("我是子进程, pid=%u, ppid=%u, var=%d\n", getpid(), getppid(), var);
	}else{
		var = 55;
		sleep(2);
		printf("我是父进程, pid=%u, ppid=%u, var=%d\n", getpid(), getppid(), var);
	}

	printf("全局代码,父进程和子进程都要执行的代码!, var = %d\n", var);
	
	return 0;
}
