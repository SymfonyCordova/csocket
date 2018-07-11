#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int sort(char **myp1/*in*/, int num1, char (*myp2)[30], int num2, char ***myp3, int *num3){
	int i = 0, j = 0, k = 0;
	int tmplen = 0;
	char **p3 = NULL;
	char *tmP = NULL;

	p3 = (char **)malloc((num1+num2)*sizeof(char *)); //里面装的是指针
	if(p3 == NULL){
		return -1;
	}

	//根据
	for(i = 0; i < num1; ++i){
		tmplen = strlen(myp1[i]) + 1;
		p3[i] = (char *)malloc(tmplen * sizeof(char));
		if(p3[i] == NULL){
			return -2;
		}
		strcpy(p3[i], myp1[i]);
	}
	
	for(j = 0; j < num2; ++j, ++i){
		tmplen = strlen(myp2[j]) + 1;
		p3[i] = (char *)malloc(tmplen * sizeof(char));
		if(p3[i] == NULL){
			return -3;
		}
		strcpy(p3[i], myp2[j]);
	}
	
	tmplen = num1 + num2;
	
	//排序
	for(i = 0; i < tmplen; ++i){
		for(j = i + 1; j < tmplen; ++j){
			if(strcmp(p3[i], p3[j]) > 0){
				//用两种交换方式 一个是改变指针的指向 另一个是交换内存块的内容
				tmP = p3[i];
				p3[i] = p3[j];
				p3[j] = tmP;
			}
		}	
	}

	//间接赋值
	*num3 = tmplen;
	*myp3 = p3;
	
	return 0;
}

void sortFree(char **p, int len){
	int i = 0;

	if(p == NULL){
		return ;
	}

	for(i = 0; i < len; ++i){
		free(p[i]);
	}

	free(p);
}

void sortFree01(char ***myp, int len){ //把二级指针执行向二维内存释放掉, 同时间接的修改了实参的值
	int i = 0;
	char **p  = NULL;
	
	if(myp == NULL){
		return ;
	}
	
	p = *myp;
	if(p == NULL){
		return ;
	}

	for(i = 0; i < len; ++i){
		free(p[i]);
	}

	free(p);

	*myp = NULL; //间接赋值是指针存在的最大意义
}


int main(){
	int ret = 0;
	int i = 0;
	char *p1[] = {"aaaaaaa", "ccccccc", "bbbbb"};
	char buf2[10][30] = {"111111", "333333", "22222"};
	char **p3 = NULL;
	int len1, len2, len3;
	
	len1 = sizeof(p1)/sizeof(*p1);
	len2 = 3;
	
	ret = sort(p1, len1, buf2, len2, &p3, &len3);
	if(ret != 0){
		printf("func sort() err:%d\n", ret);
		return ret;
	}

	for(i = 0; i < len3; ++i){
		printf("%s\n", p3[i]);
	}
	
	printf("hello...\n");
	return ret;
}
