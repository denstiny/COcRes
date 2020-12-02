#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>



#define Prot 9991
int init_socket();
int Server();
int Read(int cfd);
int sys_err(int err,char *);
int Accept(int lfd,struct sockaddr_in );
int Read(int cfd);



int main(int argc,char *argv[])
{
	int cfd,lfd = Server();
	struct sockaddr_in server_addr,clie_addr;
	pid_t pid = fork();
	

	while(1)
	{
		cfd = Accept(lfd,clie_addr);
		if(pid < 0)
		{
			sys_err(-1,"Fork");
			exit(1);
		}
		if(pid > 0)
		{
			close(cfd);
		}
	}
	if(pid == 0)
	{
		close(lfd);
		Read(cfd);
	}
	return 0;
}

int Server()
{
	int lfd = init_socket();
	return lfd;
}


int init_socket(int lfd,struct sockaddr_in server_addr)
	//绑定套接字
{

	memset(&server_addr,0,sizeof(server_addr));
	
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(Prot);
	server_addr.sin_family = AF_INET;


	lfd = socket(AF_INET,SOCK_STREAM,0);

	sys_err(bind(lfd,(struct sockaddr *)&server_addr,sizeof(server_addr)),"bind" );
	listen(100,lfd);
	return lfd;
}
int sys_err(int err,char *str)
	//出错处理
{
	if(err < 0)
	{
		perror(str);
		exit(1);
	}
	return 0;

}
int Accept(int lfd,struct sockaddr_in clie_addr)
{
	int cfd;
	socklen_t clie_len  = sizeof(clie_addr);
	sys_err(cfd = accept(lfd,(struct sockaddr *)&clie_addr,&clie_len),"accept");
	printf("New User\n");
	return cfd;
}
int Read(int cfd)
{
	char *buf = malloc(sizeof(char)*BUFSIZ);
	bzero(buf,BUFSIZ);
	while(recv(cfd,buf,sizeof(buf)*BUFSIZ,0) && *buf != '\0')
	{
		printf("%s\n",buf);
		bzero(buf,BUFSIZ);
	}
	return 0;
}
