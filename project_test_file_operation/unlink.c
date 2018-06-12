#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	//打开文件确保文件的存在
	int fd = open("tempfile", O_CREAT | O_RDWR, 0664);
	if(fd == -1){
		perror("open");
		exit(1);
	}
	//刚打开就删除file 临时文件
	int ret = unlink("tempfile");
	//write file
	write(fd, "hello\n", 6);
	
	//重置文件指针,因为此时的文件指针在末尾时都不出来任何数据
	//要想读出来，必须重置文件指针的位置
	lseek(fd, 0, SEEK_SET);
	
	// read file
	char buf[24] = {0};
	int len = read(fd, buf, sizeof(buf));//读出数据到buf，并且成功返回读到的字节数,读到0就是到末尾了
	
	// 将读出的内容，写到屏幕上
	write(1, buf, len);//1对应的是标准输出

	//close file
	close(fd);
	return 0;
}
