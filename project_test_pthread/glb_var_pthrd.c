#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int var = 100;

/*

#include <pthread.h>

       int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);

       Compile and link with -pthread.
*/

//子线程主控函数
void *pthrd(void *arg){
	var = 200;

	printf("thread\n");

	return NULL;
}

int main(void){
	pthread_t tid;
	
	printf("first pthread_create, var = %d\n", var);
	
pthread_create(&tid, NULL, pthrd, NULL);
	sleep(1);
	
	printf("after pthread_create, var = %d\n", var);
	
	return 0;	
}
