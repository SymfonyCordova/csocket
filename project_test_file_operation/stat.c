#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
				dev_t     st_dev;        
               ino_t     st_ino;         
               mode_t    st_mode;        
               nlink_t   st_nlink;       
               uid_t     st_uid;      
               gid_t     st_gid;        
               dev_t     st_rdev;        
               off_t     st_size;        
               blksize_t st_blksize;    
               blkcnt_t  st_blocks;      

               struct timespec st_atim;
               struct timespec st_mtim; 
               struct timespec st_ctim; 

*/

int main(int args, char* argv[1]){
	if(args < 2){
		perror("./a.out fileName\n");
		exit(1);
	}

	struct stat st;

	int ret = stat("english.soft", &st);	
	if(ret == -1){
		perror("stat");
		exit(1);
	}
	
	printf("%d\n", (int)st.st_dev);
	printf("%d\n", (int)st.st_blksize);	
	printf("fileSize = %d\n", (int)st.st_size);	
	return 0;
}

