#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
/**

       #include <sys/types.h>
       #include <sys/stat.h>

       int mkfifo(const char *pathname, mode_t mode);

*/
int main(void){
	const char *pathname = "testfifo"; 
	
	mkfifo(pathname, S_FIIFO | 0666);
	
	open(pathname, );
	
	return 0;
}
