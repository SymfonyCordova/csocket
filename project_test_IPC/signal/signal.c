#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

/*

	 	#include <signal.h>

       typedef void (*sighandler_t)(int);

       sighandler_t signal(int signum, sighandler_t handler);

*/

//很操蛋的是这个类型必须自己手动定义，不然编译器会报错

typedef void (*sighandler_t) (int);

//信号捕捉后的回调函数
void catchsigint(int signo){
	printf("函数捕捉后的回掉函数\n");
}

int main(void){
	sighandler_t handler;
	
	//捕捉信号,捕捉到信号后的回调函数
	//返回值是signal handler or SIG_ERR
	handler = signal(SIGINT, catchsigint);
	if(handler == SIG_ERR){
		perror("signal error");
		exit(1);
	}
	
	while(1);
	return 0;
}
