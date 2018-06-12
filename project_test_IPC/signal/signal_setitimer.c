#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

/*
int setitimer(int which, const struct itimerval *new_value,
                     struct itimerval *old_value);


struct itimerval {
	struct timeval it_interval;  // next value 
    struct timeval it_value;     // current value 
};

struct timeval {
	time_t      tv_sec;          //seconds
    suseconds_t tv_usec;         //microseconds
};


*/

void myfunc(int signo){
	printf("hello world\n");
}

//模拟alarm
unsigned int my_alarm(unsigned int sec){
	struct itimerval it, oldit;
	int ret;
	
	it.it_value.tv_sec = sec; //定时的时长,第一次定时的时间
	it.it_value.tv_usec = 0;
	
	//it.it_interval.tv_sec = 0;
	it.it_interval.tv_sec = 3; //it_interval用来设定两次定时任务之间间隔的时间
	it.it_interval.tv_usec = 0;
	
	ret = setitimer(ITIMER_REAL, &it, &oldit);
	if(ret == -1){
		perror("setitimer error");
		exit(1);
	}

	return oldit.it_value.tv_sec;
}

int main(void){
	signal(SIGALRM, myfunc); //注册SIGALRM信号的捕捉处理函数，信号被捕捉，那么不会终止进程，打印hello world
	my_alarm(5);
	
	for(int i = 0; ; ++i){
		//printf("%d\n", i);
	}
	
	return 0;
}
