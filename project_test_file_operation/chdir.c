#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	
	if(argc < 2){
		printf("a.out dir\n");
		exit(1);
	}
	
	//改变进程的工作目录
	int ret = chdir(argv[1]);
	if(ret ==-1){
		perror("chdir");
		exit(1);
	}
	
	//创建文件
	int fd = open("chdir.txt", O_CREAT | O_RDWR, 0777);
	if(fd == -1){
		perror("open");
		exit(1);
	}
	close(fd);

	char buf[128];
	getcwd(buf, sizeof(buf));
	printf("current work dir：%s\n", buf);
	return 0;
	
}
