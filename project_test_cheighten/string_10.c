#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//字符串
//1. c语言的字符串 以零结尾的字符串
//2. 在c语言中没有字符串类型 通过字符数组 来模拟字符串
//3. 字符串内存分配 堆上 栈上  全局区(很重要)

//字符数组 初始化
int main01(void){
	//1.指定长度
	char buf2[100] = {'a', 'b', 'c', 'd'};	

	//2.不指定长度 c编译器会自动帮程序员 求元素的个数
	char buf1[] = {'a', 'b', 'c', 'd'};//buf1是一个数组 不是一个以0结尾的字符串
	
	
	return 0;
}

//用字符串 来 初始化字符数组
//strlen() 长度 不包括0
//sizeof() 内存块大小
int main02(){
	int size = 0;
	char buf3[] = "abcd"; //最后一个小尾巴是\0  buf3作为字符数组,应该是5个字节 buf3作为字符串,应该4个字节
	
	int len = strlen(buf3); 
	printf("buf3字符的长度:%d\n", len);//4

	//buf3 作为数组 数组是一种数据类型(比如int) 本质(固定大小内存块的别名)
	size = sizeof(buf3);
	printf("buf3数组所占内存空间大小:%d\n", size); //5

	{

		char buf4[128] = "abcd";
		printf("buf4[100]:%d\n", buf4[100]);
	}
	
	return 0;
}

//通过数组下标 和 指针
int main(void){
	int i;
	char *p = NULL;
	char buf5[128] = "abcdefg";	

	for(i = 0; i < strlen(buf5); ++i){
		printf("%c", buf5[i]);
	}
	printf("\n");

	p = buf5; //buf5代表数组首元素的地址
	
	for(i = 0; i < strlen(buf5); ++i){
		printf("%c", *(p+i)); 
	}
	printf("\n");

	//buf5
	for(i = 0; i < strlen(buf5); ++i){
		printf("%c", *(buf5+i)); //和buf5[i]一样?
	}
	printf("\n");
	
	//buf5[i]符合人类的习惯 *(p+i)符合c编译器的习惯 []和
	//[] 和 *的推导过程 buf5[i] ==> buf5[0+i] 0是一个占位符  ==> *(buf5+i)

	{
		//buf5 = buf5 + 1; //数组一出生buf5就是一个常量指针 只读指针const (buf5临时变量如果可以改变,析构的时候内存块一部分析构 另一部不能被析构就不安全)
	}

	return 0;
}

// []的本质:和*p是一样,只不过符合程序员的阅读习惯
// buf5 是一个指针, 只读的常量 buf5是一个常量指针 析构内存的时候,保证buf所指向的内存空间安全释放
//为什么这么做? 

//p普通指针和数组首地址的区别 
