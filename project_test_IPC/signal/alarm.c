#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	int i;
	alarm(1);//1秒后发送给当前进程信号，终止当前进程
	for(i = 0;;++i){
		printf("%d\n", i);
	}

	return 0;
}
