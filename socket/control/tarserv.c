/*
 * server transfer files, This is server_addr
 * */
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#define IP 
#define PROT 8989
int main(int argc,char *argv[])
{
	int servfd = socket(AF_INET,SOCK_STREAM,0),cliefd;
	int n;
	char str[BUFSIZ];
	FILE *fp = fopen("a.png","wd");
	struct sockaddr_in server_addr,clie_addr;
	socklen_t judge = sizeof(clie_addr);
	memset(&server_addr,0,sizeof(server_addr));

	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PROT);
	server_addr.sin_family = AF_INET;

	if((bind(servfd,(struct sockaddr *)&server_addr,sizeof(server_addr))) == -1)
	{
		perror("Bind");
		exit(1);
	}
	if(listen(servfd,100) == -1)
	{
		perror("listen");
		exit(1);
	}
	if((cliefd = accept(servfd,(struct sockaddr *)&clie_addr,&judge)) == -1)
	{
		perror("accept");
		exit(1);
	}
	write(cliefd,"hello world",sizeof("hello world"));
	while(1)
	{
		memset(str,0,sizeof(str));
		fread(str,1,BUFSIZ,fp);
		write(cliefd,str,sizeof(str));
	}
	shutdown(cliefd,SHUT_RDWR);
	recv(cliefd,str,BUFSIZ,0);
	close(servfd);
	close(cliefd);
	fclose(fp);
	return 0;
}
