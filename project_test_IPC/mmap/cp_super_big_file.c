#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>

/*
	实现文件多进程拷贝
	假设有一个超大文件，需对其完成拷贝工作。为提高效率,可采用多进程并行拷贝的方法实现。
	假设文件大小为len，共有n个进程对文件进行拷贝。那每个进程拷贝的字节数应为 len/n
	但未必一定能整除，我们可一选择让最后一个进程负责剩余拷贝工作。可使用len%(len/n)将剩余部分大小求出。

	为降低实现的复杂度，可选用mmap来实现源，目标文件的映射，通过指针操作内存地址，设置每个进程拷贝的起始,结束位置。
	借助MAP_SHARED选项将内存中所做的修改反应到物理磁盘上。
*/


void sys_err(const char *str){
	perror(str);
	exit(1);
}

int main(){
	//打开文件源文件
	int fd = open("agent_data_dictionary.xlsx", O_RDONLY);
	if(fd == -1){
		sys_err("open error");
	}

	//打开文件源文件
	int fd_bak = open("agent_data_dictionary_bak.xlsx", O_RDWR | O_CREAT | O_TRUNC, 0664);
	if(fd_bak == -1){
		sys_err("open error");
	}
	
	//获取源文件的大小
	int len = lseek(fd, 0, SEEK_END);
	if(len == -1){
		sys_err("lseek error");
	}
	
	printf("file length = %d\n", len);
	
	ftruncate(fd_bak, len);
	char *mm = NULL;
	char *mmb = NULL;
	
	mm = mmap(NULL, len, PROT_READ, MAP_SHARED, fd, 0);
	if(mm == MAP_FAILED){
		sys_err("map error");
	}
	
	mmb = mmap(NULL, len, PROT_WRITE, MAP_SHARED, fd_bak, 0);
	if(mmb == MAP_FAILED){
		sys_err("map error");
	}
	
	int child_process = 4;

	int unit_length = len/child_process;

	int last_length = len%(len/child_process);

	int i;	

	printf("unit_length = %d, last_length = %d\n", unit_length, last_length);

	close(fd);
	close(fd_bak);	

	for(i = 0; i < child_process; ++i){
		int pid = fork();
		if(pid > 0){
			break;
		}else if(pid == -1){
			sys_err("fork error");
		}
	}

	if(i < child_process){//子进程
		if(i == child_process-1){
			memcpy(mmb+i*unit_length, mm+i*unit_length, unit_length+last_length);
		}else{
			memcpy(mmb+i*unit_length, mm+i*unit_length, unit_length);
		}
		
	}else{//主进程
		//回收子进程
		int status;
		int n = child_process;
		int wpid;
		do{
			wpid = wait(&status);
			if(WIFEXITED(status)){
				printf("child exit with %d\n", WEXITSTATUS(status));
			}else if(WIFSIGNALED(status)){
				printf("child signal with %d\n", WTERMSIG(status));
			}
			n--;
		}while(n > 0);
		munmap(mm, len);
		munmap(mmb, len);
	}

	return 0;
}
