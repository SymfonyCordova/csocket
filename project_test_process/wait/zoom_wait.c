#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//       pid_t wait(int *status);

int main(void){
	int pid = fork();
	if(pid == 0){//子进程
		printf("I'm child, my parent = %d, going to sleep 10s\n", getppid());
		sleep(60);
		printf("current child die\n");
		//exit(76);//只要不超过128，也就是无符号char(unsigned char)
		return 100;
	}else if(pid > 0 ){//父进程
		int status;
		int wpid = wait(&status);//三个作用 1.阻塞等待子进程退出，下面的代码将不会执行, 2.回收子进程成功返回僵尸进程的PID(wpid) 3.获取子进程的状态(int *status)
		if(wpid == -1){
			perror("wait error");
			exit(1);
		}
	
		if(WIFEXITED(status)){//判断是否正常退出
			printf("child exit with %d\n", WEXITSTATUS(status));//返回子进程的退出值
		}else if(WIFSIGNALED(status)){
			printf("child killed by signaled %d\n", WTERMSIG(status));//返回是哪个信号导致的
		}

		while(1){
			printf("I'm am parent, pid = %d, myson = %d\n", getpid(), pid);
			sleep(1);
		}
	}else{
		perror("fork error");
		exit(1);
	}

	return 0;
}
