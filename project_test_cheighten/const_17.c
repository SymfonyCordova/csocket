#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//const 有两个版本c和c++
int main(void){
	//这两个一样 常整数
	//const int a;
	//int const b;

	//const char *c;  // c是一个指向常整形的指针 (所指向的内存数据不能被修改, 但是本身可以修改)
	//char * const d; // d 常指针 (指针变量不能被修改, 但是它所指向内存空间可以被修改)
	//const char * const e; //e是一个指向常整形的常量指针 (指针和它所指向的内存空间,均不能被修改)

	//结论c语言中的const修饰的变量 是假的 c语言中的const是一个冒牌货
	const int a = 10;
	int *p = &a;
	*p = 100;
	printf("a:%d \n", a);	

	return 0;
}
