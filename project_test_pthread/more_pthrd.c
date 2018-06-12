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
	int i = (int) arg;

//	sleep(i);

	printf("In %dth thread: thread id = %lu, pid = %u\n", i+1, pthread_self(), getpid());

	return NULL;
}

int main(void){
	pthread_t tid;
	int ret, i;

	printf("In main: thread id = %lu, pid = %u\n", pthread_self(), getpid());

	for(i = 0; i < 5; ++i){	
		ret = pthread_create(&tid, NULL, thrd_func, (void *)i);//调用了pthread_create主控进程变成了主控线程
		if(ret != 0){
			fprintf(stderr, "pthread_create error: %s\n", strerror(ret));
			exit(1);
		}
	}
	
//	sleep(i);
	printf("In main: thread id = %lu, pid = %u\n", pthread_self(), getpid());
	
	//return 0;//注意这个return 将前进程退出
	pthread_exit(NULL);
}
