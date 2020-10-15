#include<unistd.h>
//#include<error.h>
//#include<errno.h>
//#include<sys/socket.h>
#include<stdio.h>
//#define BUFSIZ 4096
int main(void)
{
	int n;
	char buf[BUFSIZ];
	while((n = read(STDIN_FILENO,buf,BUFSIZ)) > 0)
	{
		if(write(STDOUT_FILENO,buf,n) != n)
			perror("write");
	}
	return 0;
}
