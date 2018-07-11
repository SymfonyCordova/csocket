#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Teacher{
	char name[64];
	char *alisname;
	char **stuname;
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
	int j = 0;
	Teacher* tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher) * num);// Teacher array[3]
	if(tmp == NULL){
		return -1;
	}
	memset(tmp, 0 , sizeof(Teacher) * num);
	
	for(i = 0; i < num; i++){
		//malloc一级指针
		tmp[i].alisname = (char *)malloc(60);
		
		//自己打造 
		{
			char **p = (char **)malloc(sizeof(char *) * 3); //打造二维内存
			for(j = 0; j < 3; ++j){
				p[j] = (char *)malloc(120);
			}
			tmp[i].stuname = p; 
		}
	}

	*pT = tmp; //二级指针 形参去间接的修改 实参的值
	return 0;
}

void freeTeacher(Teacher *p, int num){
	int i, j;
	if(p != NULL){
		return ;
	}
	for(i = 0; i < num; ++i){
		
		//释放一级指针
		if(p[i].alisname != NULL){
			free(p[i].alisname);
		}

		//释放二级指针
		if(p[i].stuname != NULL){
			char **ps = p[i].stuname;
			for(j = 0; j < 3; ++j){
				if(ps[j] != NULL){
					free(ps[j]);
				}
			}
			free(ps);
			p[i].stuname = NULL;
		}
	}
	free(p);
}

//结构体数组 3 输入老师的年龄, 排序
int main(void){
	int i, j, ret;
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

		//printf("\nplease enter name:"); 
		//scanf("%s", parr[i].name); //向指针所指的内存空间copy数据
	
		printf("\nplease enter alias:");
		scanf("%s", parr[i].alisname); //向指针所指的内存空间copy数据
	
		for(j = 0; j< 3; ++j){
			printf("please enter student name:");
			scanf("%s", parr[i].stuname[j]);
		}
	}
	
	printTeacher(parr, num);
	
	sortTeacher(parr, num);

	printTeacher(parr, num);
	
	freeTeacher(parr, num);
	return 0;
}
