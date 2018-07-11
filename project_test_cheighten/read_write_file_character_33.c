#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	FILE *fp = NULL;
	//char *filename = "c:\\1.txt";
	//char *filename = "c:/1.txt"; //统一的用45度
	char *path = "1.txt";
	char a[27] = "abcdefghijklmn";
	int i = 0;

	fp = fopen(path, "r+"); //以读和写的方式
	if(fp == NULL){
		printf("fopen error\n");
		return -1;
	}
	printf("打开成功\n");
	
	/*
	for(i = 0; i < strlen(a); i++){
		fputc(a[i], fp); //fputc
	}
	//*/
	
	//*
		while(!feof(fp)){ //是否达到文件的结尾呢
			char tmpc = fgetc(fp);
			printf("%c", tmpc);
		}
	//*/

	if(fp != NULL){
		fclose(fp);
	}

	printf("hello...\n");
	return 0;
}
