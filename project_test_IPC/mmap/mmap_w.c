#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

struct STU{
	int id;
	char name[20];
	char sex;
};

void sys_err(char *str){
	perror(str);
	exit(1);
}

int main(int argc, char *argv[]){
	int fd;
	struct STU student = {10,"xiaoming","m"};
	char *mm;

	if(argc < 2){
		printf("a.out file_shared\n");
		exit(1);
	}
	
	fd = open(argv[1], O_RDWR | O_CREAT, 0664);
	if(fd == -1){
		sys_err("open error");
	}
	
	ftruncate(fd, sizeof(student));
	
	mm = mmap(NULL, sizeof(student), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(mm == MAP_FAILED){
		sys_err("mmap error");
	}

	close(fd);
	
	//循环的想内存中写，覆盖了
	while(1){
		//有了指针那么就可以使用c基础的函数
		//字符串可以用字符串拷贝
		//这里是内存拷贝
		memcpy(mm, &student, sizeof(student));//内存拷贝
		student.id++;
		sleep(1);
	}
	return 0;
}
