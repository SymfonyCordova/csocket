#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
	int pid = fork();
	//打开只读文件,如果不存在就创建,存在就截取为0 三层含义
	int fd = open("psaux.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd == -1){
		perror("open error");
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	
	if(pid == -1){
		perror("fork error");
		exit(1);
	}else if(pid > 0){
		sleep(1);
		printf("parent\n");
	}else{
		execlp("ps", "ps", "aux", NULL);
	}

	return 0;
}
