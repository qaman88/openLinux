#include <stdio.h>
#include <float.h>

int main() {
	
	printf("**** | Basics of C Lanugage | **** \n");
	
	printf("**** | Type Size | **** \n");
	printf("int size %li bytes\n", sizeof(int));
	printf("double size %li bytes\n", sizeof(double));
	printf("float  size %li bytes min %E max %E\n", sizeof(float), FLT_MIN, FLT_MAX);
	
	return 0;
}
