#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("a.out filename\n");
		exit(0);
	}
	int ret = link(argv[1], argv[2]);
	if(ret == -1){
		perror("link");
		exit(1);
	}
	printf("create hand link file success");
	return 0;
}

