#include <stdio.h>
#include "head.h"
//#define DEBUG

int main(void)
{
	int a = NUM1;
	int aa;
	int b = NUM2;
	int sum = a + b;
#ifdef DEBUG
	printf("The sum value is: %d + %d = %d\n", a, b, sum);
#endif
	return 0;
}
