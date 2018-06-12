#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//打印未决信号集
/*
	信号三步走：自定义set -> 屏蔽信号集 -> 未决信号集
*/

void printped(sigset_t *ped){
	int i;
	for(i = 1; i < 32; ++i){
		if(sigismember(ped, i) == 1){
			putchar('1');
		}else{
			putchar('0');
		}
	}
	printf("\n");
}

int main(void){
	sigset_t myset, old_set, ped;

	//清空
	sigemptyset(&myset);
	//添加一个信号,置为1
	sigaddset(&myset, SIGQUIT);
	sigaddset(&myset, SIGTSTP);
	sigaddset(&myset, SIGINT);
	
	//将自定义的集合,,myset与屏蔽信号集关联起来
	//sigprocmask(SIG_BLOCK, &myset, NULL);//也可以不关心原来的屏蔽字设置为NULL
	sigprocmask(SIG_BLOCK, &myset, &old_set);
	
	while(1){
		//获取未决信号集的状态
		sigpending(&ped);
		//打印未决信号集
		printped(&ped);	
		sleep(1);
	}
	//以上设置了并且打印,但是产生信号可以用按键来观察
	return 0;
}
