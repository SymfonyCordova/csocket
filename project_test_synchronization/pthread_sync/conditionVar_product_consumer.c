#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

struct msg{
	struct msg *next;
	int num;
};

struct msg *head;
struct msg *mp;

/* 静态初始化 一个条件变量 和 一个互斥量  */

/* 静态初始化 一个条件变量 和 一个互斥量  */
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER; 	//相当于pthread_cond_init()动态初始化
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;      	//相当于pthread_mutex_init()动态初始化

void *consumer(void *p){								//消费者主控函数
	for(;;){
		pthread_mutex_lock(&lock); 						//加锁
		while(head == NULL){							//头指针为空,说明没有节点  可以if吗
			pthread_cond_wait(&has_product, &lock);		//3个作用 1.阻塞等待条件变量满足 
														//		  2.解锁lock
														//		  3.等待唤醒, 重新获取互斥锁
		}
		mp = head;
		head = mp->next; //模拟消费掉一个产品
		
		printf("-Consume ---%d\n", mp->num);
		free(mp);
		sleep(5);
	}
}

void *producer(void *p){//生产者主控函数

	for(;;){
		mp = malloc(sizeof(struct msg));
		mp->num = rand() % 1000 + 1;		//模拟生产一个产品
		printf("-Product ---%d\n", mp->num);
	
		pthread_mutex_lock(&lock);
		mp->next = head;
		head = mp;
		pthread_mutex_unlock(&lock);

		pthread_cond_signal(&has_product); //将等待在该条件变量上的一个线程唤醒
		sleep(3);
	}
}

//条件变量实现生产者和消费者模型
int main(int argc, char *argv[]){

	pthread_t pid, cid; //生产者,消费者
	srand(time(NULL));

	pthread_create(&pid, NULL, producer, NULL); //创建生产者线程
	pthread_create(&cid, NULL, consumer, NULL); //创建消费者线程
	
	pthread_join(pid, NULL);//回收生产者线程
	pthread_join(cid, NULL);//回收消费者线程

	return 0;
}
