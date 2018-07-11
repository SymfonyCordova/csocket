#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Teacher{
	char name[64];
	char *alisname;
	int age;
	int id;
}Teacher;

void  printTeacher(Teacher *array, int num){
	int i;
	for(i = 0; i < num; ++i){
		printf("age:%d \n", array[i].age);
	}
}

void sortTeacher(Teacher *array, int num){
	int i,j;
	Teacher tmp;
	
	for(i = 0; i < num; ++i){
		for(j = i+1; j < num; ++j){
			if(array[i].age > array[j].age){
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

//二级指针优化一下
int createTeacher(Teacher **pT, int num){
	int i = 0;
	Teacher* tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher) * num);// Teacher array[3]
	if(tmp == NULL){
		return -1;
	}
	memset(tmp, 0 , sizeof(Teacher) * num);
	
	for(i = 0; i < num; i++){
		tmp[i].alisname = (char *)malloc(60);
	}

	*pT = tmp; //二级指针 形参去间接的修改 实参的值
	return 0;
}

void freeTeacher(Teacher *p, int num){
	int i;
	if(p != NULL){
		return ;
	}
	for(i = 0; i < num; ++i){
		if(p[i].alisname != NULL){
			free(p[i].alisname);
		}
	}
	free(p);
}

//结构体数组 3 输入老师的年龄, 排序
int main(void){
	int i,ret;
	Teacher *parr = NULL;	
	int num = 3;
	
	ret = createTeacher(&parr, num);
	if(ret != 0){
		printf("func createTeacher err:%d \n", ret);
		return ret;
	}

	for(i = 0; i < num; ++i){
		printf("\nplease enter age:");
		scanf("%d", &(parr[i].age));

		printf("\nplease enter name:"); 
		scanf("%s", parr[i].name); //向指针所指的内存空间copy数据
	
		printf("\nplease enter alias:");
		scanf("%s", parr[i].alisname); //向指针所指的内存空间copy数据
	}
	
	printTeacher(parr, num);
	
	sortTeacher(parr, num);

	printTeacher(parr, num);
	
	freeTeacher(parr, num);
	return 0;
}
