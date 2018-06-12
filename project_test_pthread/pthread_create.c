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

typedef struct {
	char ch;
	int var;
	char str[64];
} exit_t;

//线程的主控函数
void *thrd_func(void *arg){
	printf("In thread: thread id = %lu, pid = %u\n", pthread_self(), getpid());
	exit_t *retval = (exit_t *)malloc(sizeof(exit_t));

	retval->ch = 'z';
	retval->var = 200;
	strcpy(retval->str, "my thread\n");
	
	//pthread_exit((void *)100);
	pthread_exit((void *)retval);
	//return NULL;
}

int main(void){
	pthread_t tid;
	int ret;	
	//int *retval;
	exit_t *retval;

	printf("In main: thread id = %lu, pid = %u\n", pthread_self(), getpid());
	ret = pthread_create(&tid, NULL, thrd_func, NULL);//调用了pthread_create主控进程变成了主控线程
	if(ret != 0){
		fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
		exit(1);
	}
	
	sleep(1);
	printf("In main: thread id = %lu, pid = %u\n", pthread_self(), getpid());
	
	pthread_join(tid, (void **)&retval);
	printf("ch = %c, var = %d, str = %s\n", retval->ch, retval->var, retval->str);
		
	free(retval);
	pthread_exit((void *)1);
	//return 0;
}
