#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//无论什么样的指针都无所谓,关键看是谁分配的内存

int main(void){
	int i;
	char* word[] = {
		"static",
		"do",
		"while",
		"case",
		'\0' //没有这一句指针数组不能结束 会发生越界
	};
	
	for(i = 0; word[i] != NULL; ++i){
		printf("%s\n", word[i]);
	}
	return 0;
}
