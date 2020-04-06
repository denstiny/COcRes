#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<errno.h>
#define PORT 6655
#define IP "127.0.0.1"
//#define Size BUFSIZ
void sys_err(char []);// 检查错误,并退出
char *s_gets(char *);
int main()
{
	int cfd;
	//int n = 0;
	//int Bool;//判断执行是否成功
	char str[BUFSIZ];
	socklen_t serv_len;
	struct sockaddr_in serv_addr;

	memset(&serv_addr,0,sizeof(serv_addr));
	//初始化套接子
	cfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	serv_addr.sin_port 	= htons(PORT);
	serv_addr.sin_family = AF_INET;
	inet_pton(AF_INET,IP,&serv_addr.sin_addr.s_addr);

	//初始化字节长度
	serv_len = sizeof(serv_addr);

	//请求连接
	connect(cfd,(struct sockaddr *)&serv_addr,serv_len);
		perror("connect");
	puts("连接成功!");
	//while(s_gets(str) != NULL && str[0] != '\n')
	while(1)
	{
		fgets(str,BUFSIZ,stdin);
//		while(getchar() != '\n')
//			continue;
	
		write(cfd,str,strlen(str));
		read(cfd,str,sizeof(str));
		puts(str);
	}
	close(cfd);
	return 0;
}
void  sys_err(char str[])
{
	perror(str);
}
char *s_gets(char *str)
{
	char *str_end = NULL,*find = NULL;
	str = fgets(str,sizeof(str),stdin);
	if(str_end)
	{
		find = strchr(str,'\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return str_end;
}
