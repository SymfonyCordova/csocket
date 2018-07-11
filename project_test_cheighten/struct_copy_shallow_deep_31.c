#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Teacher {
	char name[64];
	int age;
	char *pname2;

} Teacher;

//编译器的=号操作,只会把指针变量的值,从from copy 到 to,
//但不会 把指针变量 所指的 内存空间给copy过去.. //浅copy

//结构体中套一个一级指针 或 二级指针

//如果 想执行深copy,再显示的分配内存
void copyTeacher(Teacher *to, Teacher *from){
	*to = *from;
	//memcpy(tp, from, sizeof(Teacher));
	to->pname2 = (char *)malloc(100);
	strcpy(to->pname2, from->pname2);
}

int main(int argc, char *argv[]){
	Teacher t1;
	Teacher t2;
	
	strcpy(t1.name, "name1");
	t1.pname2 = (char *)malloc(100);
	strcpy(t1.pname2, "ssss");

	//t1 copy t2
	copyTeacher(&t2, &t1);

	if(t1.pname2 != NULL){
		free(t1.pname2);
		t1.pname2 = NULL;
	}

	if(t2.pname2 != NULL){
		free(t2.pname2);
		t2.pname2 = NULL;
	}

	printf("hello...\n");
	return 0;
}
