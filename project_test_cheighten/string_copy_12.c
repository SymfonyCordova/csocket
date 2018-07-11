#include <stdio.h>
#include <stdlib.h>

//字符串copy
//业务模型和测试代码分离 接口的封装和设计
//from形参 形参to的值不停的在变化
//不断的修改了from和to的指向
void copy_str(char *from, char *to){
	
	//for(; *from != '\0'; from++, to++){
	for(; *from != '\0';){
		*to++ = *from++; // *to = *from; from++, to++ 
	}
	
	*to = '\0';
	
	return ;
}
//很不爽 优化
void copy_str2(char *from, char *to){ //这里是形参不影响实参
	while((*to = *from) != '\0'){ //0也copy过去了 跳出去了
		from++;
		to++;
	}
}

//还是很不爽 优化
//主调函数分配内存,供被掉函数使用!!!
int copy_str3(char *from, char *to){ //这里是形参不影响实参
	//防止主调函数没有分配内存, 导致对NULL 受保护的0指针进行赋值
	if(from == NULL || to == NULL){
		return -1;
	}
	//while((*to++ = *from++) != '\0');
	while((*to++ = *from++));
	return 0;
}

//再来 最终版本
//不要轻易改变形参的值, 要引入一个辅助的指针变量, 把形参给接过来......
int copy_str4(char *from, char *to){
	char *tmpFrom = from; //辅助指针变量 作用是防止from++已经变化有些代码会有问题 比如printf
	char *tmpTo = to;      

	if(tmpFrom == NULL || tmpTo == NULL){
		return -1;
	}
	
	while((*tmpFrom++ = *tmpTo++));

	return 0;
}

int main(void){
	char a[] = "I am a student";
	char b[64];
	int i;
	char *p1 = "abcdefg"; //这个是c语言的字符串 p1指针初始化工作 将常量区的abcdefg0的地址给了p1
						  //char *p1 = 1; 这种情况编译器会把0x1赋值给p1变量 注意c语言的编译器的词法分析和句法分析
	
	//char *p2 = NULL;    //不能给0做修改,编译器不允许程序员对0号进行复制, 要先分配一个内存 buf[100]
	char buf[100];		  //分配的内存可以在 栈 堆 

	//第一种方法
	for(i=0; *(a+i) != '\0'; ++i){
		*(b+i) = *(a+i); 
	}

	b[i] = '\0';//重要
	printf("a:%s\n", a);
	printf("b:%s\n", b);	

	//第二种方法 接口的封装和设计
	copy_str(p1, buf);
	printf("buf:%s\n", buf);
	
	copy_str2(p1, buf);
	printf("buf:%s\n", buf);
	
	copy_str3(p1, buf);
	printf("buf:%s\n", buf);
	//printf("p1变量的值为:%d", p1);
	//printf("p1变量的值为:%p", p1);

	{
		//错误案例
	 	char *myto = NULL; //要分配内存 没有内存空间,哪来的指针, 没有指针还玩毛线
		//copy_str(p1, myto);
		int ret = copy_str3(p1, myto);
		if(ret == -1){
			printf("copy_str3 error\n");
		}
	}

	
	return 0;
}
