#include<stdio.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<errno.h>

#define Port 8989
#define List_len 10
char* One_serv(char *buffer);//接收主客户端数据
char* Tow_serv(char *buffer);//接收客户端数据
char* One_serv(char *buffer)
{
	//static char buffer[BUFSIZ];
	struct sockaddr_in clie_addr;
	socklen_t clie_len = sizeof(clie_addr);
	//定义sock fd
	int conn;
	int server_sockfd = socket(AF_INET,SOCK_STREAM,0);

	//初始化sockaddr
	struct sockaddr_in server_addr;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(Port);
	server_addr.sin_family = AF_INET;
	
	//bind,成功返回0，失败返回-1
	if(bind(server_sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) == -1 )
	{
		perror("bind");
		exit(1);
	}
	printf("监听端口:%d\n",Port);

	//listen,成功返回0，失败返回-1
	if(listen(server_sockfd,List_len) == -1)
	{
		perror("List");
		exit(1);
	}
	puts("等待客户端连接!");
	conn = accept(server_sockfd,(struct sockaddr *)&clie_addr,&clie_len);
	if(conn < 0)
	{
		perror("accept");
		exit(1);
	}
	memset(buffer,0,sizeof(*buffer));
	int len = recv(conn, buffer, sizeof(buffer),0);
	//客户端发送exit或者异常结束时，退出
	if(strcmp(buffer,"exit\n")==0 || len<=0)
		exit(1);
	printf("来自客户端数据：%s\n",buffer);
	send(conn, buffer, len, 0);
	printf("发送给客户端数据：%s\n",buffer);
	close(conn);
	close(server_sockfd);
	puts("连接成功");
	return buffer;
}
char *Tow_serv(char *buffer)
{
	struct sockaddr_in clie_addr;
	socklen_t clie_len = sizeof(clie_addr);
	
	int conn;
	int server_sockfd = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_addr;
	server_addr.sin_port = htons(Port);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(server_sockfd,(struct sockaddr * )&server_addr,sizeof(server_addr)) == -1)
	{
		perror("bind");
		exit(1);
	}
	printf("监听端口:%d\n",Port);

	//listen,成功返回0，失败返回-1
	if(listen(server_sockfd,List_len) == -1)
	{
		perror("List");
		exit(1);
	}
	puts("等待客户端连接!");
	conn = accept(server_sockfd,(struct sockaddr *)&clie_addr,&clie_len);
	if(conn < 0)
	{
		perror("accept");
		exit(1);
	}
	memset(buffer,0,sizeof(*buffer));
	int len = recv(conn, buffer, sizeof(buffer),0);
	//客户端发送exit或者异常结束时，退出
	if(strcmp(buffer,"exit\n")==0 || len<=0)
		exit(1);
	printf("来自客户端数据：%s\n",buffer);
	send(conn, buffer, len, 0);
	printf("发送给客户端数据：%s\n",buffer);
	close(conn);
	close(server_sockfd);
	puts("连接成功");
	return buffer;
}
int main()
{
	return 0;
}
