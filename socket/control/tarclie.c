#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#define Ip "127.0.0.1"
#define PROT 8989
int main(int argc,char *argv[])
{
	puts("hello");
	FILE *fp = fopen("/home/chroot/Imager/a.jpg","wb");
	int cfd,size;
	char str[BUFSIZ];
	struct sockaddr_in clie_addr;
	socklen_t clie_len = sizeof(clie_addr);
	
	clie_addr.sin_addr.s_addr = inet_addr(Ip);
	clie_addr.sin_family = AF_INET;
	clie_addr.sin_port = htons(PROT);
	
	memset(&clie_addr,0,sizeof(clie_addr));
	connect(cfd,(struct sockaddr *)&clie_addr,sizeof(clie_addr));
	
	while((size = read(cfd,str,sizeof(str))) != -1)
	{
		printf("%d\n",(int)sizeof(str));
		fwrite(str,1,size,fp);
	}
	fclose(fp);
	close(cfd);
	return 0;
}
