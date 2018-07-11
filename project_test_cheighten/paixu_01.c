#include <stdio.h>
#include <stdlib.h>

//打印数组
void print_array(int *arr, int len){
	int i, j;
	for(i = 0; i < len; ++i){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//排序
//void sortArray(int arr[9], int len){
//void sortArray(int arr[], int len){
void sortArray(int *arr, int len){
	int i, j, tmp;
	int num2; //形参写在括号上面和写在函数体里面的效果是一样的,只不过写在括号上面具有了对外的属性而已

	num2 = sizeof(arr)/sizeof(arr[0]);
	printf("num:%d\n", num2);
	//实参的arr和形参的a的数据类型本质不一样
	//形参中的数组,编译器会把它当成指针处理
	//为什么编译器会把数组变成指针传进去?因为数组内存时很大的,而指针内存小,这样无形中就大大提高了c语言的效率
	//c语言的优势就是在主调函数和被调函数之间用指针来操作内存,这是c语言的特色	
	
	for(i = 0; i < len; ++i){
		
		for(j = i+1; j < len; ++j){
			if(arr[i] > arr[j]){
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		
	}
}

//数组做函数参数的退化问题  退回为一个指针 
//结论：1.把数组的内存首地址和数组的有效长度传给被调用函数
//		2.实参的a和形参的arr的数据类型本质不一样
//			形参中的数组,编译器或把它当成指针处理,这是c语言的特色
//      3.形参写在括号上面和写在函数体里面的效果是一样的,只不过写在括号上面具有了对外的属性而已

int main(void){
	int len;
	int a[] = {33, 654, 4, 455, 6, 33, 4, 22, 34};
	
	//获取数组的元素个数
	len = sizeof(a)/sizeof(a[0]);
	
 	printf("排序之前: ");
	print_array(a, len);
	
	printf("len = %d\n", len);
	sortArray(a, len);
	
	printf("排序之后: ");
	print_array(a, len);
	return 0;
}
