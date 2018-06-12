#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int var = 100;

int main(void){
	int fd, pid;
	int *p = NULL;
	
	fd = open("temp", O_RDWR|O_CREAT|O_TRUNC, 0664);
	if(fd == -1){
		perror("open error");
		exit(1);
	}
	unlink("temp"); //删除临时文件目录项,使之具备被释放的条件,unlink是在被使用的全部进程结束时才被真正的删除
	ftruncate(fd, 4);//通过文件扩展函数来得到文件的大小
	//注意,此时的MAP_PRIVATE和MAP_SHARED在父子进程中的意思时不一样的
	//如果是MAP_PRIVATE:父子进程各自独占映射区
	//如果是MAP_SHARED:父子进程共享映射区,所以父子进程要想共享进程必须设置为MAP_SHARED
	//p = (int *)mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	p = (int *)mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	if(p == MAP_FAILED){ //注意:不是p == NULL
		perror("mmap error");
		exit(1);
	}
	//映射区建立完毕，即可关闭文件
	close(fd);
	
	//创建子进程
	pid = fork();
	if(pid == 0){//子进程
		*p = 2000;
		var = 1000;
		printf("child, *p = %d, var = %d\n", *p, var);
	}else if(pid > 0){//主进程
		sleep(1);
		printf("parent, *p = %d, var = %d\n", *p, var);
		wait(NULL);
		
		int ret = munmap(p, 4); //释放映射区
		if(ret == -1){
			perror("munmap error");
			exit(1);
		}
	}else{
		perror("fork error");
		exit(1);
	}
	
	return 0;
}
