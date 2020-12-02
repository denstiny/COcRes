#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
	int n;
	char buf[BUFSIZ];
	while( (n = read(STDIN_FILENO,buf,BUFSIZ)) > 0 )
		if(write(STDOUT_FILENO,buf,n) != n)
			exit(1);
	return 0;
}
