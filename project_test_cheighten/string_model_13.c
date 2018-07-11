#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//strstr_while模型
//char *p = "abcd111122abcd33333322abcd33333322qqq"; //求字符串p中 abcd出现的次数
//1请自定义函数接口,完成上述需求
//2自定义的业务函数和main函数必须分开

int main01(void){
	
	//初始化 让p指针达到查找的条件
	char *p = "11abcd111122abcd33333322abcd33333322qqq";
	int ncount = 0;
	
	do{
		p = strstr(p, "abcd");
		if(p != NULL){
			ncount++;
			p = p + strlen("abcd");//指针达到下次查找的条件
		}else{
			break;
		}
	}while(*p!='\0');	
	
	printf("ncount:%d\n", ncount);
	return 0;
}

int main02(void){
	
	//初始化 让p指针达到查找的条件
	char *p = "11abcd111122abcd33333322abcd33333322qqqabcd";
	int ncount = 0;
	
	while((p = strstr(p, "abcd"))){
		ncount++;
		p = p + strlen("abcd"); //让p指针达到查找的条件
		if(*p == '\0'){
			break;
		}
	}
	
	printf("ncount:%d\n", ncount);
	return 0;
}

int getStrNum(char *mystr/*in*/, char *sub/*in*/, int *ncount/*out*/){
	int tmpCount = 0;
	char *tmp1 = mystr;
	char *tmp2 = sub;

	if(ncount == NULL || tmp1 == NULL || tmp2 == NULL){
		return -1;
	}
	
	while((tmp1 = strstr(tmp1, tmp2))){
		tmpCount++;
		tmp1 = tmp1 + strlen(tmp2);
		if(*tmp1 == '\0'){
			break;
		}
	}

	*ncount = tmpCount;//间接赋值时指针存在的最大意义

	return 0; 
}

int main(void){
	int count = 0;
	char *p = "11abcd111122abcd33333322abcd33333322qqqabcd";
	//char sub[] = "abcd";
	int ret = getStrNum(p, "abcd", &count);

	if(ret == -1){
		printf("getStrNum error");
		exit(1);
	}

	printf("ncount:%d\n", count);

	return 0;
}
