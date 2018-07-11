#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

       size_t fwrite(const void *ptr, size_t size, size_t nmemb,
                     FILE *stream)

*/

//直接把内存数据 写入到 文件中
typedef struct Teacher {
	char name[64];
	int age;
} Teacher;

void my_fwrite(){
	int i = 0;
	FILE *fp = NULL;
	char *fileName = "3.data";
	Teacher tArray[3];
	int n = 0;
	
	/*
	for(i = 0; i < 3; ++i){
		sprintf(tArray[i].name, "%d%d%d", i+1, i+1, i+1);
		tArray[i].age = i + 31;
	}
	//*/

	//fp = fopen(fileName, "wb");
	fp = fopen(fileName, "rb");
	if(fp == NULL){
		printf("建立文件失败\n");
		return;
	}

	for(i = 0; i < 3; ++i){
		//函数的参数：
		//从内存块的开始ptr 
		//内存打包技术size  
		//写多少次nmemb 
		//写入到的文件指针所指向的文件中stream
		
		//函数的返回值 写入成功的次数
		//n = fwrite(&tArray[i], sizeof(Teacher), 1, fp);
		
		//n 判断 有没有写满 磁盘
		
		n = fread(&tArray[i], sizeof(Teacher), 1, fp);
	}

	//* 打印
    for(i = 0; i < 3; ++i){
  		printf("name:%s, age:%d\n", tArray[i].name, tArray[i].age);
    }
    //*/
	

	if(fp != NULL){
		fclose(fp);
	}
}

int main(int argc, char *argv[]){
	my_fwrite();
	printf("hello...\n");
	return 0;
}
