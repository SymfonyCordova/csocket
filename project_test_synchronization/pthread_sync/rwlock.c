#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
/* 3个线程不定时 "写" 全局变量, 5个线程不定时 "读"*/
int counter;
pthread_rwlock_t rwlock;  //全局资源

void *th_write(void *arg){
	int t;
	int i = *((int *)arg);
	
	while(1){
		t = counter;
		usleep(1000);

		pthread_rwlock_wrlock(&rwlock); //以写方式加锁
		printf("====write %d: %lu: counter=%d ++counter=%d\n", i, pthread_self(), t, ++counter);
		pthread_rwlock_unlock(&rwlock); //释放锁

		usleep(5000);
	}
	return NULL;
}

void *th_read(void *arg){
	int i = *((int *)arg);
	
	while(1){
		pthread_rwlock_rdlock(&rwlock);			//以读方式加锁
		printf("----read %d: %lu: %d\n", i, pthread_self(), counter);
		pthread_rwlock_unlock(&rwlock);			//释放锁
	
		usleep(900);
	}
	return NULL;
}

int main(void){
	int i;
	pthread_t tid[8];

	pthread_rwlock_init(&rwlock, NULL); //对读写锁进行初始化

	for(i = 0; i < 3; ++i)
		pthread_create(&tid[i], NULL, th_write, (void *)&i);	
	
	for(i = 0; i < 5; ++i)
		pthread_create(&tid[i+3], NULL, th_read, (void *)&i);	

	for(i = 0; i < 8; ++i)
		pthread_join(tid[i], NULL);
	
	pthread_rwlock_destroy(&rwlock); //销毁读写锁

	return 0;
}
