#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//有一个字符串符合以下特征("abcdef,acccd,eee,aaaa,e3eeee,ssss,";)

int spitString(const char *buf1, char c, char buf2[10][30], int *count){
	
	
	return 0;
}

int main(void){
	
	int ret = 0;
	char *p1 = "abcdef,acccd,eee,aaaa,e3eeee,ssss,";
	char cTem = ',';
	char myArray[10][30];
	int count;
	int i = 0;
	
	ret = spitString(p1, cTem, myArray, &count);
	if(ret != 0){
		printf("spit String error\n");
		exit(1);
	}

	for(i = 0; i < count; ++i){
		printf("%s\n", myArray[i]);
	}
	
	return 0;
}
