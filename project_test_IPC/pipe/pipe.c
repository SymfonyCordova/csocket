#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void){
	int fd[2];
	int pid, wpid, status;

	int ret = pipe(fd);//创建管道，两个段 fd[1]写 fd[0]读, pipe 必须保证进程之间是有血缘关系
	if(ret == -1){
		perror("pipe error");
		exit(1);
	}
	
	pid = fork();//主进程掌握着两段,子进程也掌握着两段
	if(pid == -1){
		perror("fork error");
		exit(1);
	}else if(pid == 0){//子进程， 设置为读数据
		//子进程要将写段关闭，读段开启，因为管道的单向数据流
		close(fd[1]);
		char buf[1024];
		ret = read(fd[0], buf, sizeof(buf));
		if(ret == 0){
			printf("read finish\n");
		}
		write(STDOUT_FILENO, buf, ret);
		
	}else{//父进程, 设置写数据
		//父进程要将读段关闭，写段开启，因为管道收单向数据流
		close(fd[0]);
		write(fd[1], "hello pipe\n", strlen("hello pipe\n"));	
		wpid = waitpid(-1, &status, WNOHANG);
		if(wpid > 0){
			if(WIFEXITED(status)){
				printf("wait with exit %u\n", WEXITSTATUS(status));
			}else{
				printf("wait with signal%u\n", WTERMSIG(status));
			}
		}
	}
	
	return 0;
}
