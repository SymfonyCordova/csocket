#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int i = 0;
	
	//指针数组
	char * p1[] = {"123", "456", "789"};

	//二位数组
	char p2[3][4] = {"123", "456", "789"};
	
	//手工二维内存
	char ** p3 = (char **)malloc(sizeof(char *) * 3);
	for(i = 0; i < 3; ++i){
		p3[i] = (char *)malloc(3 * sizeof(char));
		sprintf(p3[i], "%d%d%d", i, i, i);
	}

	return 0;
}
