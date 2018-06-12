#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/*
	int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);
*/


//线程的主控函数
void *thrd_func(void *arg){
	pthread_cond_timedwait();
	pthread_exit((void *)77);
}

int main(void){
	pthread_t tid;
	int ret;	
	pthread_attr_t attr;

	ret = pthread_attr_init(&attr);
	if(ret != 0){
		fprintf(stderr, "pthread_attr_init error: %s\n", strerror(ret));
		exit(1);
	}
	
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	ret = pthread_create(&tid, &attr, thrd_func, NULL);//调用了pthread_create主控进程变成了主控线程
	if(ret != 0){
		fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
		exit(1);
	}
	
	ret = pthread_join(tid, NULL);
	if(ret != 0){
		fprintf(stderr, "pthread_join error: %s\n", strerror(ret));
		exit(1);
	}
	pthread_exit((void *)1);
}
