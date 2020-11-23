/*********************************************************************************
 *     File Name           :     ServerHtml.c
 *     Created By          :     chroot
 *     Creation Date       :     [2020-11-16 08:43]
      Last Modified       :     [2020-11-18 10:07]
 *     Description         :     web服务器 for c
 **********************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include <fcntl.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#define PROT 2000

int create_listenfd(void);
void  headle_request(int fd);
int send_(int fd,char *buf,int *len);
void cat(int client,FILE *request_file);
int Read(int clie_fd,char *file_name);


int main(int argc,char *argv[])
{
	//1。创建监听套接字
	int sockfd = -1,fd = -1;
	struct sockaddr_in server_clie;
	bzero(&server_clie,sizeof(server_clie));

	socklen_t clie_len = sizeof(server_clie);
	sockfd=create_listenfd();

	printf("SOCKFD ==> %d\n",sockfd);
	if(sockfd == -1)
	{
		puts("套接字绑定失败");
		while(sockfd != -1)
		{
			puts("重新绑定套接字");
			sockfd=create_listenfd();
		}
	}

	//2 接收客户端连接
	while(1)
	{
		while(fd == -1){
			puts("等待连接...");
			fd=accept(sockfd,(struct sockaddr *)&server_clie,&clie_len);
		}
		perror("Accept");
		puts("新增一位用户");
		//3.处理请求
		headle_request(fd);
		//3. 处理客户端请求
		close(fd);
		fd = -1;
	}

	close(sockfd);
}
int create_listenfd(void)
{
	int fd = socket(AF_INET,SOCK_STREAM,0),rest,prot;
	struct sockaddr_in sin;
	bzero(&sin,sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PROT);
	sin.sin_addr.s_addr = INADDR_ANY;
	for(prot = PROT ;(rest = bind(fd,(struct sockaddr *)&sin,sizeof(sin))) == -1;prot++)
	{
		sin.sin_port = htons(prot);
	}
	perror("Bind");
	printf("Prot ==>%d\n",prot);

	listen(fd,100); perror("listen");
	return fd;
}
void  headle_request(int fd)
{
	char buffer[BUFSIZ],File_Name[10]={0};
	char *Index=NULL,Request[1024*1024] = {0};
	int size_buf;

	int nred = read(fd,buffer,sizeof(buffer));
	printf("客户端数据 ==>\n%s\n",buffer);
	//解析数据
	sscanf(buffer,"GET /%s",File_Name);
	printf("FILE_TYPE==>%s\n",File_Name);
	if(strstr(File_Name,".html")) Index="text/html";

	if(strstr(File_Name,".jpg")) Index = "image/jpg";

	sprintf(Request,"HTTP/1.1 200 OK\r\nContent-Type: %s\r\n\r\n",Index);
	//sprintf 将index 打印到　Request
	int head_len = strlen(Request);

	size_buf = sizeof(Request);
	send(fd,Request,sizeof(Request),0);
	Read(fd,File_Name);
}
int send_(int fd,char *buf,int *len)
	//发送数据给客户端
{
	printf("发送==>%s\n",buf);
	int s = send(fd,buf,*len,0);
	if(s == -1)
		return -1;
	return 0;

}
int Read(int clie_fd,char *file_name)
{
	char Request[1024*1024] = {0},*Index =NULL;
	int file_re = 0;
	FILE *fp = fopen(file_name,"rb");

	if(fp == NULL)
		return -1;  
	while((file_re = fread(Request,1,sizeof(Request),fp)) > 0)
	{
		if(file_re <= 0)
		{
			perror("Read");
			return -1;
		}
		send_(clie_fd,Request,&file_re);
	}
	return 0;
}
