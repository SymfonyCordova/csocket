#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int fd;//定义一个文件描述符
	
	/*
	fd = open("bucunzi", O_RDWR);
	if(fd == -1){
		//perror("open file"); 
		//exit(1); 
	}
	*/

	//创建新文件
	fd = open("myhello", O_RDWR | O_CREAT, 0777);//八进制
	if(fd == -1){
		perror("open file"); 
		exit(1); 
	}
	printf("fd = %d\n", fd);	

	//open()判断文件是否存在(必须是O_CREAT|0_EXCL)
	/*
	fd = open("myhello", O_RDWR | O_CREAT | O_EXCL, 0777);//八进制
	if(fd == -1){
		perror("open file"); 
		exit(1); 
	}
	*/
	 
	//open()将文件截断为0(必须是O_CREAT|0_EXCL)
	fd = open("myhello", O_RDWR | O_TRUNC);//八进制
	if(fd == -1){
		perror("open file"); 
		exit(1); 
	}

	//关闭文件
	int ret = close(fd);
	if(ret == -1){
		perror("close file"); 
		exit(1); 
	}
}
