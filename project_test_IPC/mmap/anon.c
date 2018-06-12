#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int var = 100;

int main(void){
	int  pid;
	int *p = NULL;
	
	p = (int *)mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	if(p == MAP_FAILED){ //注意:不是p == NULL
		perror("mmap error");
		exit(1);
	}
	
	//创建子进程
	pid = fork();
	if(pid == 0){//子进程
		*p = 2000;
		var = 1000;
		printf("child, *p = %d, var = %d\n", *p, var);
	}else if(pid > 0){//主进程
		sleep(1);
		printf("parent, *p = %d, var = %d\n", *p, var);
		wait(NULL);
		
		int ret = munmap(p, 4); //释放映射区
		if(ret == -1){
			perror("munmap error");
			exit(1);
		}
	}else{
		perror("fork error");
		exit(1);
	}
	
	return 0;
}
