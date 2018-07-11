#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//获取非空格的字符串长度
int getCount(char *str, int *pCount){
	
	char *p = str;
	int i = 0; 
	int j = 0;
	int count = 0;
	j = strlen(p)-1;

	if(str == NULL || pCount == NULL){
		return -1;
	}

	while(isspace(p[i]) && p[i] != '\0'){
		i++;
	}

	while(isspace(p[j]) && p[j] != '\0'){
		j--;
	}

	count = j-i+1;
	*pCount = count;
	return 0;
}

//去除字符串前后的空格, 中间的不管
int trimSpace(char *str, char *newstr){
	
	char *p = str;
	int i, j, count;
	j = strlen(p)-1;

	if(str == NULL || newstr == NULL){
		return -1;
	}

	while(isspace(p[i]) && *(p+i) != '\0'){
		i++;
	}

	while(isspace(p[j]) && *(p+j) != '\0'){
		j--;
	}
	count = j -i + 1;

	strncpy(newstr, str+i, count);

	newstr[count] = '\0';

	return 0;
}

int main(void){
	char p[] = "    abcdefgabc    ";
	char buf[1024] = {0};
	int count = 0;
	int ret = 0;

	ret = getCount(p, &count);
	if(ret == -1){
		printf("getCount error\n");
		exit(1);
	}	

	printf("count:%d\n", count);


	ret = trimSpace(p, buf);
	if(ret == -1){
		printf("getCount error\n");
		exit(1);
	}	

	printf("buf:%s\n", buf);

	return 0;
}
