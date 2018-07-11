#include <stdio.h>
#include <string.h>
#include <stdio.h>

char g_buf[1024];

//字符串翻转
int inverse(char *str){

	char *p1 = str;
	int length = strlen(str);
	char *p2 = str + length - 1;

	if(str == NULL){
		return -1;
	}	

	while(p1 < p2){
		char c = *p1;
		*p1 = *p2;
		*p2 = c;
		++p1;
		--p2;
	}
	return 0;
}

//递归实现翻转,逆向打印
//递归和全局变量(把逆序的结果存入全局变量)
//递归和非全局变量(递归指针做函数参数)

void recursion_inverse(char *str){
	if(str == NULL){
		return ;	//递归结束的异常条件
	}

	if(*str == '\0'){//递归结束的条件
		return ;
	}
	
	recursion_inverse(str+1);//注意 此时没有执行打印,而是执行了 让字符串的
	
	//printf("%c", *str);
	strncat(g_buf, str, 1);
}

void r_inverse(char *str, char *newstr){
	
	if(str == NULL || newstr == NULL){
		return ;	//递归结束的异常条件
	}

	if(*str == '\0'){//递归结束的条件
		return ;
	}
	
	r_inverse(str+1, newstr);
	
	strncat(newstr, str, 1);
}

int main(void){
	char buf[] = "abcdefg";
	char mybuf[1024] = {0};
	memset(g_buf, 0, sizeof(g_buf));

	//inverse(buf);
	//printf("buf:%s\n", buf);

	recursion_inverse(buf);
	printf("g_buf:%s\n", g_buf);//使用全局变量在多线程中会造成数据乱序的问题
	
	r_inverse(buf, mybuf);
	printf("mybuf:%s\n", mybuf);

	return 0;
}
