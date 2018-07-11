#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Teacher{
	char name[64];
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
	Teacher* tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher) * num);// Teacher array[3]
	if(tmp == NULL){
		return -1;
	}
	*pT = tmp; //二级指针 形参去间接的修改 实参的值
	return 0;
}

void freeTeacher(Teacher *p){
	if(p != NULL){
		free(p);
	}	
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
		printf("please enter age:");
		scanf("%d", &(parr[i].age));
	}
	
	printTeacher(parr, num);
	
	sortTeacher(parr, num);

	printTeacher(parr, num);
	
	freeTeacher(parr);
	return 0;
}
