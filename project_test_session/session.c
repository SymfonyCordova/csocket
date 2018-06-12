#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	pid_t pid;

	if((pid = fork()) < 0){
		perror("fork error");
		exit(1);
	}else if(pid == 0){//子进程
		/*获取当前进程的pid pgid sessionid*/
		printf("child process PID is %d\n", getpid());
		printf("group PID of child is %d\n", getpgid(0));
		printf("session ID of child is %d\n", getsid(0));
		
		sleep(10);
		setsid(); //子进程非组长进程, 故其成为新会话首进程,且成为组长进程.该进程组ID即为会话进程

		printf("changed:\n");

		/*获取当前进程的pid pgid sessionid*/
		printf("child process PID is %d\n", getpid());
		printf("group PID of child is %d\n", getpgid(0));
		printf("session ID of child is %d\n", getsid(0));
		
		sleep(20);

		exit(0);
	}

	return 0;
}
