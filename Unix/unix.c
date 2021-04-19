#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<limits.h>
int main( int argc, char *argv[] ) {
	clock_t t;
	printf("%ld\n",_POSIX_C_SOURCE);
	printf("%d\n",PATH_MAX);
	sleep(1);
	printf("%ld\n",t);
	return 0;
}

