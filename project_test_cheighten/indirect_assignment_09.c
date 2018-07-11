#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//间接赋值的三个条件
//1.定义1个变量(实参) 定义一个变量(形参)
//2.建立关联:把实参取地址传给形参
//3.形参去间接的修改了实参的值

int getMem(char **p1/*out*/, int *len1/*out*/, char **p2/*out*/, int *len2/*out*/){
	int ret = 0;
	char *tmp1, *tmp2;
	
	tmp1 = (char *)malloc(100);
	strcpy(tmp1, "abcd123");

	//间接赋值
	*len1 = strlen(tmp1); //1级指针
	*p1 = tmp1; //2级指针的间接赋值

	tmp2 = (char *)malloc(100);
	strcpy(tmp2, "abwecd123");

	//间接赋值
	*len2 = strlen(tmp2); //1级指针 
	*p2 = tmp2; //2级指针的间接赋值
	
	return ret;
}

//间接赋值是指针做函数参数的最大意义 

int main(void){
	int ret = 0;
	char *p1 = NULL;
	int len1 = 0;
	char *p2 = NULL;
	int len2 = 0;

	//指针做函数参数非常重要
	//主函数调用子函数获取数据
	//主函数完成一个任务,写很多子函数,调用子函数获取结果
	//主业务和子功能进行分层 接口的封装和设计
	ret = getMem(&p1, &len1, &p2, &len2);
	if(ret != 0){
		printf("getMem error:%d", ret);
		return ret;
	}

	printf("p1:%s\n", p1);
	printf("p2:%s\n", p2);

	if(p1 != NULL){
		free(p1);
		p1 = NULL;
	}
	
	if(p2 != NULL){
		free(p2);
		p2 = NULL;
	}

	return 0;
}
