#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int fd = open("aa", O_RDWR);
	if(fd == -1){
		perror("open file");
		exit(1);
	}	
	//文件的大小
	int ret = lseek(fd, 0, SEEK_END);
	printf("file length = %d\n", ret);

	//文件的扩展
	ret = lseek(fd, 2000, SEEK_END);
	printf("return value = %d\n", ret);

	//文件的扩展,需要再最后做一次写操作
	write(fd, "a", 1);
	
	close(fd);
	return 0;
}
