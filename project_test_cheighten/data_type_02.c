#include <stdlib.h>
#include <stdio.h>

//数据类型的用途
//数据类型的本质:固定大小内存块的别名
//b &b 数组数据类型 (定义一个1数组类型, 2数组指针 3数组类型和数组指针类型的关系)
//

void main01(void){
	int a; //告诉c编译器分配4个字节的内存
	int b[10];  //告诉c编译器分配40个字节内存

	//b+1 &b+1 结果不一样 //b &b所代表的数据类型不一样
	//b代表数组首元素的地址     b+1 一跳跳了一个单元(4个字节)
	//&b代表的是整个数组的地址	&b+1 一跳跳了一个数组大的单元(40个字节)

	printf("b=%d, b+1=%d, &b=%d, &b+1=%d\n", b, b+1, &b, &b+1);		

	printf("sizeof(b)=%d\n", sizeof(b)); //40
	printf("sizeof(a)=%d\n", sizeof(a)); //4
}


struct Teacher{
	char name[64];
	int age;
} Teacher;

//数据别名
typedef struct Teacher2{
	char name[64];
	int age;
} Teacher2;

void main(){
	struct Teacher t1;
	t1.age = 31;
		
	Teacher2 t2;
	t2.age = 31;

	{
		char *p2 = NULL;
		void *p1 = NULL;
		p2 = (char *)malloc(100); //malloc 返回的是void * 所以要强制转换
		
		p1 = &p2; 
	}

}
