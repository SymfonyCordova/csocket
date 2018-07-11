#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//野指针产生的原因
//指针变量和它所指向的内存空间变量是两个不同的概念
//释放了指针的内存空间 但是指针变量本身没有重置成NULL;
//造成释放的时候 通过if()判断不出来

//避免方法: 定义指针的时候初始化为NULL, 释放指针所指向的内存空间以后,把指针重置为NULL。
int main(){
	char *p1 = NULL;
	
	p1 = (char *)malloc(100);//在堆区里面申请了一块内存,内存里面数据的类型是char 指针每次步调是1个字节(char)
	if(p1 == NULL){
		exit(1);
	}
	
	strcpy(p1, "111222");//将静态区的常量111222内容拷贝到p1所指向的内存空间里, 而p变量的值是malloc后的内存地址

	printf("p1:%s", p1);

	if(p1 != NULL){
		free(p1);
		p1 = NULL;//没有这已经会产生野指针
	}

	printf("hello...\n");

	if(p1 != NULL){
		free(p1);
		//同样的道理 p1要再次重置位NULL
		p1 = NULL;
	}

	
	//char *p2 = NULL; //0指针不能copy数据,因为0号指针是收操作系统保护的
	//char *p2 = 0x777; //也不能自己直接指定,因为你不知道内存到底有没有,有没有在被使用,要借助操作系统帮我们区弄指针的地址
	//strcpy(p2, "abcdefg");

	int i;
	int j;
	char buf[128]; //在栈中分配了一个内存
	char *p3 = NULL;
	
	p3 = &buf[0]; //不断的修改p3的值 相当于不断改变p3的指向
	p3 = &buf[1];
	p3 = &buf[2];

	for(i = 0; i < 10; ++i){
		p3 = &buf[i];
	}

	char *p4 = (char *)malloc(100);
	for(i = 0; i < 10; ++i){
		p3 = p4+i;
	}

	return 0;
}
