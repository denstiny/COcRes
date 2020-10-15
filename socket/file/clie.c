#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(int argc,char *argv[])
{
	int cfd = socket(AF_INET,SOCK_STREAM,0);
	char str[BUFSIZ] = {0};
	struct sockaddr_in clie_addr;
	int  fp = open("a.desktop",O_RDWR);
	memset(&clie_addr,0,sizeof(clie_addr));


	//clie_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	inet_pton(AF_INET,"127.0.0.1",&clie_addr.sin_addr.s_addr);
	clie_addr.sin_port = htons(8989);
	clie_addr.sin_family = AF_INET;
	
	connect(cfd,(struct sockaddr *)&clie_addr,sizeof(clie_addr));
	perror("connect");
	while(read(cfd,str,sizeof(cfd)) != -1)
	{
		puts(str);
		//fwrite(str,sizeof(str),1,fp);
		write(fp,str,sizeof(str));
	}
	close(cfd);
return 0;}
