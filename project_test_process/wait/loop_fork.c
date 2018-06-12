#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM 5

int main(void){
	
	int i, pid, q, wpid, n;
	for(i = 0; i < NUM; ++i){
		pid = fork();
		if(pid == 0){
			break;
		}else if(pid == -1){
			perror("fork error");
			exit(1);
		}else{
			if(i == 3){//特别青睐三儿子
				q = pid;
			}	
		}
	}
	
	if(i < NUM){//子进程
		sleep(i);	
		printf("I'm %dth child pid = %u, ppid = %u\n", (i+1), getpid(), getppid());
		exit(i);
	}else{//父进程
		sleep(NUM);
		printf("I'm parent, pid = %u\n", getpid());
		//while(wait(NULL));
		//waitpid(q, NULL, 0);//设置0阻塞等待回收和wait一样
		//while(waitpid(-1, NULL, 0));//-1表示回收任意子进程,清理所有的子进程
		n = NUM;
		do{
			wpid = waitpid(-1, NULL, WNOHANG);
			//if wpid == 0 说明子进程正在运行
			if(wpid > 0){
				n--;
			}
			sleep(1);
		}while(n > 0);	
		//while(1);
		printf("waitpid finish\n");
	}

	return 0;
}
