#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

/*

       int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);

*/

typedef struct{
	int a;
	int b;
} exit_t;

/*子线程的主控函数*/
void *tfd(void *arg){
	exit_t *ret;
	ret = malloc(sizeof(exit_t));
	
	ret->a = 100;	
	ret->b = 300;

	pthread_exit((void *)ret);
}

int main(void){
	pthread_t tid;
	exit_t *retval;

	pthread_create(&tid, NULL, tfd, NULL);

	/*调用pthread_join可以获取线程的退出状态*/
	pthread_join(tid, (void **)&retval);
	printf("a = %d, b = %d\n", retval->a, retval->b);
	
	return 0;
}
