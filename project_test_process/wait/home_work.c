#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
	int i, pid, status, wpid;
	int n = 3;
	for(i = 0; i < 3; ++i){
		pid = fork();
		if(pid == 0){
			break;
		}else if(pid == -1){
			perror("fork error");
			exit(1);
		}
	}
	
	if(i < 3){//子进程
		sleep(i);
		printf("I'm child pid = %d, ppid = %d, I excle proces\n", getpid(), getppid());
		if(i == 0){ //执行ps命令
			execlp("ps", "ps", "aux", NULL);	
		}else if(i == 1){//执行自定义程序1(正常程序)
			execl("./process1", "process1", NULL);	
		}else{//执行自定义程序2(会出现段错误程序)
			execl("./process2", "process2", NULL);
		}
	}else{//父进程
		sleep(n);
		printf("I'm parent\n");
		do{
			wpid = waitpid(-1, &status, WNOHANG);
			if(wpid > 0){
				if(WIFEXITED(status)){
					printf("wait pid = %d child with exit = %u\n", wpid, WEXITSTATUS(status));
				}else if(WIFSIGNALED(status)){
					printf("wait pid = %d child with signal = %u\n",wpid, WTERMSIG(status));
				}
				n--;
			}
		}while(n >0 );
		printf("wait finish\n");
		while(1);
	}
	
	return 0;
}
