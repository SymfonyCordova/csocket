#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

//根据key获取value
int getKeyByValue(char *keyvaluebuf, char *key, char *value){
	
	if(keyvaluebuf == NULL || key == NULL || value == NULL){
		return -1;
	}

	char *p = NULL;
	int ret = 0;	

	//1查找key是不是在母串中
	p = keyvaluebuf; //初始化辅助指针变量
	p = strstr(p, key);
	if(p == NULL){
		return -1;
	}
	//让辅助指针变量 重新达到下一次检索的条件
	p = p + strlen(key);

	//2看有没有=号
	p = strstr(p, "=");
	if(p == NULL){
		return -1;
	}
	p = p + strlen("=");

	//3在等号后面 去除空格
	ret = trimSpace(p, value);
	if(ret == -1){
		printf("trimSpece error\n");
		return ret;
	}

	return ret;
}
	
int main(void){
	int ret = 0;
	char buf[1024] = {0};

	char *keyandvalue = "key2=         value2  ";
	char *key = "key2";

	ret = getKeyByValue(keyandvalue, key, buf);
	if(ret == -1){
		printf("getKeyByValue error\n");
		exit(1);
	}
	
	printf("buf:%s\n", buf);
	return 0;
}
