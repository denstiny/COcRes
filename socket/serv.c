#include<ctype.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<sys/types.h>
#include<arpa/inet.h>
#define PORT 6655
#define IP "127.0.0.1"
void sys_err(char []);
int main()
{
	char str[BUFSIZ];
	int lfd,cfd;
	socklen_t clie_len;
	struct sockaddr_in serv_addr,clie_add;

	memset(&serv_addr,0,sizeof(serv_addr));

	lfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
		sys_err("socket");
	
	//初始化套接字长度
	clie_len = sizeof(clie_add);
	//初始化网络套接字
  	//serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //ip地址
	inet_pton(AF_INET,IP,&serv_addr.sin_addr.s_addr);
	serv_addr.sin_family = AF_INET; 			// 协议类型 
	serv_addr.sin_port = htons(PORT); 			// 端口号
	//绑定套接字
	bind(lfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
		sys_err("bind");
	printf("serv_addr for ip is %d\n",serv_addr.sin_addr.s_addr);

	//指定连接个数
	listen(lfd,128);
		sys_err("listen");

	puts("等待连接 .....");
	//阻塞等待
	cfd = accept(lfd,(struct sockaddr *)&clie_add,&clie_len);
		sys_err("cfd for accept");
	puts("连接成功!");
	while(1)
	{
		read(cfd,str,sizeof(str));
	//	if(str[0] != '\n' && str[0] != '\0')
		 	puts(str);
		fgets(str,sizeof(str),stdin);
		//while(getchar() != '\n')
		//	continue;
		write(cfd,str,strlen(str));
	}
	close(cfd);
	close(lfd);
		sys_err("close");
	return 0;
}
void sys_err(char str[])
{
	perror(str);
}
