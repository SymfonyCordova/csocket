#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void){
	pid_t pid, sid;
	int ret;	

	//创建子进程
	pid = fork();
	if(pid > 0 ){
		return 0;
	}

	//子进程脱离成为会话
	sid = setsid();
	
	//修改当前的工作目录
	ret = chdir("/home/symfony");
	if(ret == -1){
		perror("chdir error");
		exit(1);
	}
	
	//文件权限掩码
	umask(0002);
	
	//将标准输入，标准输出, 标准错误重定向
	//close(0);
	close(STDIN_FILENO);
	open("/dev/null", O_RDWR);
	dup2(0, STDOUT_FILENO);
	dup2(0, STDERR_FILENO);

	//子进程的主逻辑,周期性干事情
	while(1){
		//退出,用一个信号捕捉来进行自杀
	}
		

	return 0;
}
