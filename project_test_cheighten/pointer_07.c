#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getStr(){
	char *tmp = 1;
	tmp = "abcdefg";
	return tmp;
}

/*
	int getABC1(char *p1);
	int getABC2(char **p2);
	int getABC3(char ***p3);
	int getABC4(char (*p4)[30]);
	int getABC5(char p5[10][30]);
	
	指针做函数参数,形参有多级指针的时候,
	站在编译器的角度, 只需要分配4个字节的内存(32bit平台)
								8个字节的内存(64bit平台)
	
	当我们使用内存的时候，我们才关心指针所指向的内存 是一维的还是二维的
	
	那指针前面的类型是什么意思呢? 指针是一种数据类型，意思是它指向的内存空间的数据类型
	这样指针的步长(p++)才能确定,根据所指内存空间的数据类型来确定
	
*/

int main(){
	int a = 10;
	char *p1 = 2; //分配8个字节 64位操作系统和32位操作系统不一样
	char ****p2 = 100;
	char b = 'c';
	char *pstr = getStr();

	int *p3 = NULL;
	p3 = &a;

	*p3 = 20;//间接的修改a的值
	// * 就像一把钥匙 通过一个地址(&a),去修改a变量的标识的内存空间
	
	{
		int c = 0;
		c = *p3;
		//*p放在=号左边 写内存
		//*p放在=号右边 读内存
		printf("c的值 = %d\n", c);
	}	
	
	//不断的给指针赋值, 相当于不停的改变指针的指向
	{
		char *p4 = NULL;
		p4 = (char *)malloc(100);
		p4 = (char *)malloc(200);
	}

	printf("p1=%p\n", p1);	//通过%p和%d 说明指针初始化时指针变量的值就是=号后面的值(是一个内存空间的标号)

	printf("a的大小%d, b的大小%d, p1的大小%d, p2的大小%d\n", sizeof(a), sizeof(b), sizeof(p1), sizeof(p2));	

	printf("pstr的指向内存的标号=%p", pstr);
	*(pstr+2) = 'r'; //会出现段错误  因为pstr指向的是一个常量区不能被修改的 保证指针指向的内存空间 可以被修改
	

	return 0;
}
