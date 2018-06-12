#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	char *p = NULL;
	
	int fd = open("mmap.txt", O_CREAT | O_RDWR, 0644);
	if(fd == -1){
		perror("open error");
		exit(1);
	}

	int len = ftruncate(fd, 4);//ftruncate(专门做文件扩展的函数),来获取文件的大小
	if(len == -1){
		perror("ftruncate error");
		exit(1);
	}
	
	//mmap映射 
	//映射区的大小length不能为0也就是说新创建的文件不能为O
	//创建映射区的权限必须小于等于文件的权限
	//创建映射区第一次隐含着对文件的读操作
	//创建映射区的文件的便宜位置offset 必须是4k的整数倍,因为映射区是MMU帮我创建的而MMU映射的时候的单位是4k
	p = mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	//mmap这些参数都会出错，所以必须要检查是否出错
	if(p == MAP_FAILED){
		perror("mmap error");
		exit(1);
	}
	
	//使用指针的方法来写入数据
	strcpy(p, "abc");
	
	//释放映射区
	//p不要随意的++，--操作，否则不能成功释放映射区
	//必须保证创建时候的首地址和释放的首地址一致
	//通常的方式是声明变量保存起来,然后在随意的操作
	int ret = munmap(p, 4);
	if(ret == -1){
		perror("munmap error");
		exit(1);
	}
		
	//关闭文件 文件的描述符先mmap关闭和后关闭都可以
	//因为映射区一旦建立后,和之前的文件没有关系了
	close(fd);
	
	return 0;
}
