#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//变量的是分配后一段连续内存空间的别称
//变量的生命周期
void main(){
	int a;
	int *p;
	a = 10; //直接赋值

	printf("&a=%d\n", &a);
	
	//间接赋值  == 直接通过内存
	*((int *)1245024) = 200;//假如知道了a地址

	{
		p = 12345024;//间接赋值 通过指针
		*p = 300;
	}	

	//对内存空间能不能在取别名...

	printf("&a=%d\n", &a);

}
