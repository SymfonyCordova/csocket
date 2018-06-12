#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void){
	
	char *p = "我们是一个有中国特色的社会主义国家!!!!!!";
	char *q = "呵呵，社会主义好哇......";
	
	//只写的方式打开文件
	int fd = open("test.txt", O_WRONLY);
	if(fd == -1){
		perror("open");
		exit(1);
	}
	
	//输入新的内容，该部分会覆盖原来旧的内容
	if(write(fd, p, strlen(p)) == -1){
		perror("write");
		exit(1);
	}

	//使用F_GETFL命令得到文件状态标志
	int flag = fcntl(fd, F_GETFL, 0);
	if(flag == -1){
		perror("fcntl");
		exit(1);
	}
	
	//将文件状态标志添加"追加写"选项
	flag |= O_APPEND;
	if(fcntl(fd, F_SETFL, flag) == -1) {
		perror("fcntl -- append write");
		exit(1);
	}

	//再次输入新的内容,该内容追加到旧内容的后面
	if(write(fd, q, strlen(q)) == -1){
		perror("write again");
		exit(1);
	}
	
	//关闭文件
	close(fd);
	
	return 0;
}
