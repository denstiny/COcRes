#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<errno.h>
#include<string.h>

#define Port 9909


int main()
{
	int servfd[2],i = 0;
	char *clie_str = (char *)malloc(sizeof(clie_str));
	//char *str = (char *)malloc(BUFSIZ *sizeof(str));
	char str[BUFSIZ];

	int cfd,lfd = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in clie_addr,server_addr;

	socklen_t clie_len = sizeof(clie_addr);
	//初始化

	memset(&server_addr,0,sizeof(server_addr));

	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(Port);
	server_addr.sin_family = AF_INET;

	//bind 套接字
	if(bind(lfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) == -1)
	{
		perror("Bind");
		exit(-1);
	}
	printf("监听端口 :%d\n",Port);

	//listen 阻塞等待
	if(listen(lfd,10) == -1)
	{
		perror("Listen");
		exit(-1);
	}
	while((cfd = accept(lfd,(struct sockaddr *)&clie_addr,&clie_len)) != -1)
	{
		printf("%s",inet_ntop(AF_INET,&clie_addr.sin_addr.s_addr,str,sizeof(str)));
		printf("%d号机连接成功\n",i+1);
		servfd[i] = cfd;
		i++;
		if(i == 2)
			break;
	}
	write(servfd[0],"一号机连接成功\n",sizeof("一号机连接成功\n"));
	write(servfd[1],"二号机连接成功\n",sizeof("二号机连接成功\n"));
	while(1)

	{
		bzero(str,sizeof(str));
		read(servfd[0],str,sizeof(str));
		printf("来自客户端数据：%s\n",str);
		write(servfd[1],str,sizeof(str));
		printf("发送给客户端数据：%s\n",str);
	}
	close(lfd);
	close(cfd);
	return 0;
}
