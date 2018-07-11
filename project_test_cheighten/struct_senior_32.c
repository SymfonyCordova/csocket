#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//一旦结构体定义下来,则结构体中的成员..内存布局 就定下了
//可以通过age地址，去求 大的结构体的内存地址
typedef struct AdvTeacher {
	char name[64]; //64
	int age; //4
	int *p; //4
	char *pname2; //4

} AdvTeacher;



int main(int argc, char *argv[]){
	AdvTeacher t1;
	AdvTeacher *p = NULL;
	p = &t1;
	//p = p + 100;
	//strcpy(p1, "dddd"); //出错
	//p - 1; //能编译通过吗？ 能运行通过吗？编译通过 运行通过 这句话 在cpu中计算

	{
		int offsize = (int)&(p->age); //
		int offsize2 = (int)&(((AdvTeacher *)0)->age);
		printf("%d\n", offsize);
		printf("%d\n", offsize2);
	}
	
	printf("hello...\n");
	return 0;
}
