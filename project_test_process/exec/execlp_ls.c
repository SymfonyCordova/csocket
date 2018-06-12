#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	int pid = fork();
	
	int fd = open("psaux.txt", O_CREAT | O_EXCL, 0777);

	if(pid == -1){
		perror("fork error");
		exit(1);
	}else if(pid > 0){
		sleep(1);
		printf("parent\n");
	}else{
		//execlp("ls", "ls", "-l", "-a", NULL);
		//execl("/bin/ls", "ls", "-l", "-a", NULL);
		//execl("./while", "while", NULL);
		char *argv[] = {"ls", "-l", "-a", "-h", NULL};
		execv("/bin/ls", argv);
	}

	return 0;
}
