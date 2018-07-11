#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	FILE *fp = NULL;
	char *path = "2.txt";
	//char a[27] = "abcdefghijklmn";
	char buf[1024];

	fp = fopen(path, "rw+"); //以读写的方式 如果文件不存在 则新建
	if(fp == NULL){
		printf("fopen error\n");
		return -1;
	}
	printf("打开成功\n");

	//fputs(a, fp);	
	//1.//c函数库会一行一行的copy数据到buf指针所指的内存空间 并且变成c风格的字符串
	//2.把\n也copy到我们的buf
	//3.内存打包(把内存首地址 + 内存的长度)
	while(!feof(fp)){
		char *p = fgets(buf, 1024, fp); //c函数库会一行一行的copy数据到buf指针所指的内存空间 并且变成c风格的字符串
		if(p == NULL){
			goto End;
		}
		printf("%s", buf);
	}

End:
	if(fp != NULL){
		fclose(fp);
	}

	printf("hello...\n");
	return 0;
}
