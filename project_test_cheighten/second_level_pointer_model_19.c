#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//二级指针做输入的
void print_arr(char **arr, int len){
	int i = 0;	
	for(i = 0; i < len; ++i){
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(arr+i));
	}
}

void sort_arr(char **arr, int len){
	int i, j;
	char *tmp = NULL;
	for(i = 0; i < len; ++i){
		for(j = i; j < len; ++j){
			if(strcmp(arr[i], arr[j]) > 0){
				tmp = arr[i];
				arr[i] = arr[j]; //注意 交换的是数组元素 交换的是指针的值 改变的是指针的指向
				arr[j] = tmp;
			}
		}
	}
}

//问题的本质是 二级指针做输入的第二种内存模型的 myArray + 1
			  //二级指针做输入的第一种内存模型 myArray + 1 不一样
//指针的步长不一样 指针所指向的内存空间的数据类型不一样
void print_arr02(char arr[10][30], int len){
	int i = 0;	
	for(i = 0; i < len; ++i){
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(arr+i));
	}
}

//交换的是内存块
void sort_arr02(char arr[10][30], int len){
	int i = 0;
	int j = 0;
	char tmpBuf[30];
	for(i = 0; i < len; ++i){
		for(j = i+1; j < len; ++j){
			if(strcmp(arr[i], arr[j]) > 0){
				strcpy(tmpBuf, arr[i]); 	//交换的是内存块
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], tmpBuf);
			}
		}
	}		
}

char **getMem(int num){
	int i = 0;
	char **p2 = NULL; 	
	p2 = (char **)malloc(sizeof(char *) * num);
	if(p2 == NULL){
		return NULL;
	}

	for(i = 0; i < num; ++i){
		p2[i] = (char *)malloc(sizeof(char) * 100); //相当于char buf[100]
		sprintf(p2[i], "%d%d%d", i+1, i+1, i+1);
	}
	
	return p2;
}

void print_arr03(char **arr, int len){
	int i = 0;	
	for(i = 0; i < len; ++i){
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(arr+i));
	}
}

void sort_arr03(char **arr, int len){
	int i, j;
	char *tmp = NULL;
	for(i = 0; i < len; ++i){
		for(j = i; j < len; ++j){
			if(strcmp(arr[i], arr[j]) > 0){
				tmp = arr[i];
				arr[i] = arr[j]; //注意 交换的是数组元素 交换的是指针的值 改变的是指针的指向
				arr[j] = tmp;
			}
		}
	}
}

void getMemFree03(char **p, int num){

	int i = 0;
	//释放内存
	for(i = 0; i < num; ++i){
		if(p[i]  != NULL){
			free(p[i]);
			p[i] = NULL;
		}
	}

	if(p != NULL){
		free(p);
	}
}

//第一种指针数组是编译器给我们打造的一个数据模型
//第二种多维数组也是编译器给我们打造的一个数据模型
//第三种是程序员自己打造的数据模型
int main(void){
	char **p2 = NULL;
	int num = 5;
	//int j = 0;
	//char *tmp = NULL;
	//char tmpbuf[100];

	p2 = getMem(num);
	//排序之前：
	printf("排序之前 \n");
	print_arr03(p2, num);
	//排序 
	//交换了指针的指向
	/*
	for(i = 0; i < num; ++i){
		for(j = i+1; j < num; ++j){
			if(strcmp(p2[i], p2[j]) < 0){
				tmp = p2[i];
				p2[i] = p2[j];
				p2[j] = tmp;
			}
		}
	}
	*/

	//排序 
	//交换内存块
	/*
	for(i = 0; i < num; ++i){
		for(j = i+1; j < num; ++j){
			if(strcmp(p2[i], p2[j]) < 0){
				strcpy(tmpbuf, p2[i]);
				strcpy(p2[i], p2[j]);
				strcpy(p2[j], tmpbuf);
			}
		}
	}*/
	
	sort_arr03(p2, num);
	
	//排序之后：
	printf("排序之后 \n");
	print_arr03(p2, num);
	
 	//释放内存
	getMemFree03(p2, num);//p2是一个野指针

	return 0;
}

int main02(void){
	//char myBuf[30];
	char myArray[10][30] = {"aaaaa", "ccccc", "bbbbbbb", "111111111111111111"};
	//int i = 0;	
	int num = 4;
	//int j = 0;

	//myArray：编译器只会关心:有10行，每列30列。。。。。干什么? myArray+1 多维数组的本质
	{
		int len1 = sizeof(myArray);
		int len2 = sizeof(myArray[10]);
		int size = len1/len2;
		printf("len1:%d, len2:%d size:%d \n", len1, len2, size);
	}

	//打印
	printf("排序之前 \n");
	print_arr02(myArray, num);

	sort_arr02(myArray, num);

	//打印
	printf("排序之后 \n");
	print_arr02(myArray, num);

	return 0;
}

int main01(void){
	int num;
	//数组， 数组每个元素是指针
	char *myArray[] = {"aaaaaa", "ccccc", "bbbbbb", "111111"};
	
	//打印
	num = sizeof(myArray)/sizeof(myArray[0]);
	
	printf("排序之前\n");
	print_arr(myArray, num);

	//排序
	sort_arr(myArray, num);

	printf("排序之后\n");
	print_arr(myArray, num);
	return 0;
}
