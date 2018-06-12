#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void){
	int pid = fork();
	if(pid > 0){//主进程
		printf("parent, myson = %d\n", pid);
		int status;
		int wpid = wait(&status);
		if(wpid == -1){
			perror("wait error no child process");
			exit(1);
		}
		
		if(WIFEXITED(status)){//正常退出
			printf("child wait with exit: %d\n", WEXITSTATUS(status));
		}else if(WIFSIGNALED(status)){//非正常
			printf("child wait with single: %d\n", WTERMSIG(status));
		}
	
	}else if(pid == 0){//子进程
		printf("I‘m child going to sleep(5), pid = %d\n", getpid());
		sleep(5);
		printf("current child die\n");
		exit(29);
	}else{
		perror("fork error");
		exit(1);
	}
	return 0;
}
