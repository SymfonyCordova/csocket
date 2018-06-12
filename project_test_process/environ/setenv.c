#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char *val;
	const char *name = "ABD";
	
	val = getenv(name);
	printf("1, %s = %s\n", name , val);

	setenv(name, "haha-dav-and-night", 1);
	
	val = getenv(name);
	printf("2, %s = %s\n", name , val);

#if 0
	int ret = unsetenv("ABDFGH");
	printf("ret = %d\n", ret);

	val = getenv(name);
	printf("3, %s = %s\n", name , val);
#else
	int ret = unsetenv("ABCEFJEW=");
	printf("ret = %d\n", ret);
	
	val = getenv(name);
	printf("3, %s = %s\n", name , val);
#endif
	return 0;	
}
