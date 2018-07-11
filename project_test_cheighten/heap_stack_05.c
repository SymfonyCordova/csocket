#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//堆
char *getMem(int num){
	char *p1 = NULL;
	p1 = (char *)malloc(sizeof(char) * num);
	if(p1 == NULL){
		 return NULL;
	}
	return p1;
}

//栈
//注意return 不是把内存块64个字节,给return出来, 而不把内存的首地址(内存的标号0xaa11), 返回给tmp

//理解指针的关键,是内存, 没有内存哪来的指针
char *getMem2(){
	char buf[64]; //临时变量 栈区存放
	strcpy(buf, "123456789");
	printf("buf = %s\n", buf);
	return buf; //此时buf在函数调用完之后,内存的空间析构掉了
}

void main(){
	
	char *tmp = NULL;
	tmp = getMem(10);
	if(tmp == NULL){
		return ;
	}
	strcpy(tmp, "111222");//向tmp所指向的内存空间中copy数据
	printf("tmp = %s\n", tmp);
	
	tmp = getMem2();	//栈的内存空间析构掉了,就指向了一个不存在内存空间的地址，报错 崩溃 死机 NULL
	//相当于tmp = 0xaa11
	printf("tmp = %s\n", tmp);

	return ;
}
