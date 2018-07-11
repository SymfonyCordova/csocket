#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//证明多维数组内存存储是线性的
void print_arr(int *arr, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
}

int main(void){
	int a[3][5];
	int i,j;
	int tmp = 1;
	
	for(i = 0; i < 3; ++i){
		for(j = 0; j < 5; ++j){
			a[i][j] = tmp++;
		}
	}
	
	//把二维数组 当成 1维数组 来打印 证明线性存储
	print_arr((int *)a, 15);
	printf("hello...\n");
	return 0;
}

//总结
/*
	二维数组可以看做是一维数组
	二维数组中的每一元素是一维数组
	二维数组参数中的第一维的参数可以省略
	
	void f(int a[5]) ==> void f(int a[]) ==> void f(int* a)
	void g(int a[3][3]) ==> void g(int a[][3]) ==> void g(int (*a)[]3)

	等价关系：
		数组参数                 等效的指针参数
		一维数组char a[30]       指针char *
		指针数组char* a[30]      指针的指针 char **a
		二维数组char a[10][30]   数组指针char (*a)[30]

*/
