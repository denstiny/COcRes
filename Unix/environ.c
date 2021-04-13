#include<stdio.h>
int main( int argc, char *argv[] ) {
	extern char **environ;
	for(int i = 0;i <= 5;i++)
		printf("%s\n",environ[i]);
	return 0;
}

