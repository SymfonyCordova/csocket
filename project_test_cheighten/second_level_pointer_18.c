#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//指针做输出:被调函数分配内存
//指针做输入:主调函数分配内存
//求文件中两段话的长度
int getMem(char **myp1, int *mylen1, char **myp2, int *mylen2){
	char *tmp1 = NULL;
	tmp1 = (char *)malloc(100);
	if(tmp1 == NULL){
		return -1;
	}
	strcpy(tmp1, "abcdefg"); 
	*mylen1 = strlen(tmp1);
	
	*myp1 = tmp1;//间接修改实参p1的值
	
	char *tmp2 = NULL;
	tmp2 = (char *)malloc(100);
	if(tmp2 == NULL){
		return -2;
	}
	strcpy(tmp2, "wxyz700i"); 
	*mylen2 = strlen(tmp2);

	*myp2 = tmp2;//间接修改实参p2的值

	return 0;
}

//释放内存
int getMemFree(char **myp1){ 
	char *tmp = NULL;
	if(myp1 == NULL){
		return -1;
	}
	tmp = *myp1;
	free(tmp); //释放指针变量所指的内存空间
	*myp1 = NULL; //把实参修改成NULL, 
				  //如果传的是一级指针,不能改变实参为NULL会出现野指针
				  //这就是一级指针和二级指针的区别
}

int main(void){
	char *p1 = NULL;
	char *p2 = NULL;
	int len1;
	int len2;
	int ret;

	ret = getMem(&p1, &len1, &p2, &len2);
	printf("p1:%s, len1:%d\n", p1, len1);
	printf("p2:%s, len2:%d\n", p2, len2);

	getMemFree(&p1);
	getMemFree(&p2);
	return 0;
}
