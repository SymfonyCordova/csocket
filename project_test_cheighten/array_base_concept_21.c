#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void){
	//1.如何定义数组和初始化
	//int b[] = {1,2};
	//int b2[100] = {1,3};

	int c[200] = {0}; //编译的时 就已经确定 所以的值
	//对一位数组 c规定
	//c是数组首元素的地址 c+1 步长 4/8个字节 c是个常量
	//&c是整个数组的地址 &c+1 步长 200*4/8字节
	memset(c, 0, sizeof(c));//显示的 重置内存块
	
	//2.怎么样表达int a[10]这种数据类型？int[]
	//类型的本质:固定大小内存块的别名
	//定义数组类型
	typedef int (MyArrayType)[5]; //定义了一个数据类型 数组数据
	MyArrayType arr;              //相当于 int arr[5];
	int i = 0;

	for(i = 0; i < 5; ++i){
		arr[i] = i+1;
	}

	for(i = 0; i < 5; ++i){
		printf("%d\n", arr[i]);
	}

	printf("arr是数组首元素的地址 arr:%d, arr+1:%d\n", arr, arr+1);
	printf("&arr是整个数组的地址 &arr:%d, &arr+1:%d\n", &arr, &arr+1);
	
	//3.指针数组和数组指针
	//char *arr1[] = {"aaa", "bbbb", "cccc"}; //指针数组
	//数组指针 用一个指针来指向一个数组
	
	//3.1数组指针第一种方法
	typedef int (ArrayType)[5];
	//ArrayType arr2; 
	ArrayType *arrp; //定义了一个指针变量 这个指针变量 指向一个数组
	
	{
		int arr2[5];//相当于一级指针
		for(i = 0; i < 5; ++i){
			arr2[i] = i+1;
		}
	
		arrp = &arr2;//相当于2级指针
		for(i = 0; i < 5; ++i){
			printf("%d\n", (*arrp)[i]);
		}
	}
	printf("以上为数组指针的第一种方法\n");
	//3.2数组指针第二种方法
	//定义声明一个数组指针类型
	typedef int (*ArrayPointerType)[5];
	ArrayPointerType parr; //告诉编译器 给我分配一个指针变量
	
	int cc[5];
	parr = &cc;
	
	for(i = 0; i < 5; ++i){
		(*parr)[i] = i + 1;
	}
		
	for(i = 0; i < 5; ++i){
		printf("%d\n", (*parr)[i]);
	}
	printf("以上为数组指针的第二种方法\n");

	//3.3数组指针第三种方法
	//前两种方法 通过类型定义变量 比较麻烦
	int (*parr2)[5]; //直接定义一个指向数组的 数组指针变量
	
	int d[5];
	parr2 = &d;
	
	for(i = 0; i < 5; ++i){
		(*parr2)[i] = i + 1;
	}
		
	for(i = 0; i < 5; ++i){
		printf("%d\n", (*parr2)[i]);
	}
	
	printf("以上为数组指针的第三种方法\n");
	
	return 0;
}

