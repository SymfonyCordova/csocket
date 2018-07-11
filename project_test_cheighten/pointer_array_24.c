#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define DIM(a) (sizeof(a))/sizeof(*a)

//求关键字在表中的位置
//一个入口 多个出口
int searchKeyTable(const char* table[], const int size, const char* key, int *pos){
	int rv = 0;
	int i = 0;
	//int inum = 0;

	if(table == NULL || key == NULL || pos == NULL){
		rv = -1;
		printf("func searchKeyTable:%d", rv);
		return rv;
	}
	
	//间接证明 数组做函数参数的退化
	//inum = (sizeof(table)/sizeof(*table));
	//printf("%d", inum)

	for(i = 0; i < size; ++i){
		if(strcmp(key, table[i]) == 0){
			*pos = i;
			return rv;
		}
	}
	
	//没有找到返回-1
	if(i == size){
		*pos = -1;
	}

	return rv;
}

//指针数组案例
int main(int argc, char* argv[], char** env){
	//int inum = 0;
	int pos = 0;
	//int a[10];
	int i = 0;

	//指针数组
	char* c_keyword[] = {
		"while",
		"case",
		"static",
		"do"
	};
	
	searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);

	printf("pos:%d\n", pos);

	printf("********** Begin argv **********\n");
	for(i = 0; i < argc; ++i){
		printf("%s\n", argv[i]);
	}
	printf("********** Begin env **********\n");
	for(i = 0; env[i] != NULL; ++i){
		printf("%s\n", env[i]);
	}
	
	return 0;
}

