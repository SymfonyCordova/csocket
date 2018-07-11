#include <stdio.h>
#include <stdlib.h>

//堆和栈的属性

//栈的开口向上向下,一般认为:栈的开口向下
//不管栈的开口向上还是向下,buf的内存地址buf+1,永远向上的
//栈的生长方向和buf的内存增长方向 是两个不同的概念 不要混淆
int main(){
	int a;
	int b;
	
	char buf[128]; //编译的时候,buf所代表的内存空间的标号 就已经定义下来了

	printf("&a = %d, &b = %d\n", &a, &b);

	return 0;
}
