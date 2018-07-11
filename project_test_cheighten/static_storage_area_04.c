#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *getStr1(){
	char *p = "abcdefg2";
	return p;
}

char *getStr2(){
	char *p2 = "abcdefg2";
	return p2;
}

//1.指针指向谁 就把谁的地址赋值给指针
//2.指针变量和他所指向的内存空间变量是两个不同的概念
int main(void){
	char *p1 = NULL;
	char *p2 = NULL;
	p1 = getStr1();
	p2 = getStr2();
	
	//打印p1, p2 内存空间里面的数据
	printf("p1 = %s, p2 = %s\n", p1, p2);
	
	//打印p1, p2的值
	//printf("p1 = %d, p2 = %d\n", p1, p2);
	
	printf("hello...\n");
	return 0;
}
