/*********************************************************************************
*     File Name           :     ssh.c
*     Created By          :     Aero
*     Github              :     Aero denstiny
*     Creation Date       :     [2020-05-20 22:12]
*     Last Modified       :     [2020-10-10 18:03]
*     Description         :     my serv.c 
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
typedef struct socekt_link
{
	int socket_link;
	struct socket_link *next;
}sock;
void* Read();
int cfd;
int main(int argc,char *argv[])
{
	int lfd,n,i = 0,a=0;
	int intnet[BUFSIZ];
	char str[BUFSIZ],clie_str,sstr[BUFSIZ] ;
	pid_t id;
	pthread_t wr,re,xs;
	struct sockaddr_in serv,clie;
	socklen_t serv_len,clie_len;
	serv_len = sizeof(serv);
	clie_len = sizeof(clie);
	lfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	memset(&serv,0,sizeof(serv)); //初始化套接字
	serv.sin_family = AF_INET;
	serv.sin_port = htons(6655);
	serv.sin_addr.s_addr = htons(INADDR_ANY);
	//绑定套接字
	bind(lfd,(struct sockaddr *)&serv,serv_len);
	// 限制连接数量
	listen(lfd,128);
	//等待连接
	//读取客户端发送的数据 
	printf("%d",getpid());
	while(1)
	{
		cfd = accept(lfd,(struct sockaddr *)&clie,&clie_len);
		intnet[i] = cfd;i++;
		printf("%d ===>进入聊天室\n",clie.sin_addr.s_addr);
		id = fork();
		if(id == 0)
		{
			close(lfd);
			break;
		}else if(id == -1)
		{
			perror("for errno");
			exit(1);
		}
	}
	if(id == 0)
	{
		while(1)
		{
			memset(str,0,sizeof(str));
			memset(sstr,0,sizeof(sstr));
			n = read(cfd,str,sizeof(str));
			if(n <= 0)
			{
				close(cfd);
				printf("%d===> 离开聊天室\n",clie.sin_addr.s_addr);
				i--;
				return 0;
			}
			else if(n > 0)
			{
				for(n = 0;n < i;n++)
					write(intnet[n],str,strlen(str));
				printf("%s",str);
			}
		}
	}
	close(cfd);
	close(lfd);
	return 0;
}
int  Tree_Link(int Socket)
	// socket list
{
	sock *head = NULL,*last = NULL;
	sock* One_Socket = malloc (sizeof(sock));
	if(One_Socket == NULL)
	{
		printf("One_Socket is  NULL\n");
		exit(1);
	}
	if(head == NULL)
	{
		head = One_Socket;
		head->next = NULL;
		last = head;
	}
	else
	{
		last->next = One_Socket;
	}
	while(One_Socket != NULL)
	{
		One_Socket->socket_link = Socket;
		One_Socket->next = NULL;
	}
	
	return 0;
}
