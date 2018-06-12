#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/*
     #include <pthread.h>
       int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);

       Compile and link with -pthread.
*/

//线程的主控函数
void *thrd_func(void *arg){
	printf("In thread: thread id = %lu, pid = %u\n", pthread_self(), getpid());
	return NULL;
}

int main(void){
	pthread_t tid;
	int ret;	
	
	printf("In main: thread id = %lu, pid = %u\n", pthread_self(), getpid());
	ret = pthread_create(&tid, NULL, thrd_func, NULL);//调用了pthread_create主控进程变成了主控线程
	if(ret != 0){
		fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
		exit(1);
	}
	
	printf("In main: thread id = %lu, pid = %u\n", pthread_self(), getpid());
	
	//return 0;这个是退出真个线程
	pthread_exit((void *)1);//pthread_exit是将主控线程退出掉,不会退出整个进程
}
