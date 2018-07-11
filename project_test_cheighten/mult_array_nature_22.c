#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//多维数组的本质
int main(void){
	int a[3][5], i = 0, j = 0;
	int tmp = 1;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 5; ++j){
			a[i][j] = tmp++;
		}
	}
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 5; ++j){
			printf("%d ", a[i][j]);
		}
	}
	
	//a 多维数组名 代表?
	printf("a:%d, a+1:%d ", a, a+1); //a+1的步长 是20个字节 5*8
	printf("&a:%d, &a+1:%d ", &a, &a+1);

	{
		//定义一个指向数组的指针变量 
		int (*parr)[5];//告诉编译器 分配4个字节的内存 32bit平台下
		parr = a;
		
		for(i = 0; i < 3; i++){
			for(j = 0; j < 5; ++j){
				printf("%d ", parr[i][j]);
			}
		}
	}
	
	//多维数组名的本质 就是数组指针，步长 一维的长度
	// (a+i) 代表是整个第i行的首地址 二级指针
	// *(a+i) 代表 1级指针 第i行首元素的地址
	// *(a+i)+j ===》&a[i][j]
 
	// *(*(a+i)+j) ===》a[i][j]元素的值

	//a[i][j]  <===> *(*(a+i)+j)

	//a[i] ==> a[0+i] ==> *(a+i)
	
	//a[i][j] ==> a[0+i][j] ==> *(a+i)[j] ==> *(a+i)[0+j] ==> *(*(a+i)+j)
	
	// [] ==> *()

	printf("hello \n");
	return 0;
}
