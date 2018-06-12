#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

void *tfn(void *arg){
	int n = 3;
	while(n--){
		printf("thread count %d\n", n);
		sleep(1);
	}
	return (void *)1;
}

int main(void){
	pthread_t tid;
	void *tret;
	int err;

//子线程从主线程分离两种办法一个是pthread_create 设置属性
//还有就是pthread_detach

#if 1
	
	pthread_attr_t attr;    /*通过线程属性来设置游离状态*/
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&tid, &attr, tfn, NULL);

#else 

	pthread_create(&tid, NULL, tfn, NULL);
	pthread_detach(tid);				//让线程分离 --自动退出,无系统残留资源

#endif
	//周期性回收子进程
	while(1){
		err = pthread_join(tid, &tret);
		printf("------------err= %d\n", err);
		if(err != 0){
			fprintf(stderr, "thread_ioin error: %s\n", strerror(err));
		}else{
			fprintf(stderr, "thread exit code %d\n", (int)tret);
		}
		sleep(1);
	}

	return 0;
}
