#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<error.h>
int main(int argc,char *argv[])
{
	int lfd = socket(AF_INET,SOCK_STREAM,0),cfd;
	FILE *fp = fopen("/home/chroot/Desktop/steam.desktop","r+");
	char str[BUFSIZ] = {0};
	struct sockaddr_in serv_addr,clie_addr;
	socklen_t clie_len = sizeof(clie_addr);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(8989);
	serv_addr.sin_family = AF_INET;
	bind(lfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));perror("bind");
	listen(lfd,100);
	accept(lfd,(struct sockaddr *)&clie_addr,&clie_len);
	while(fread(str,sizeof(str),1,fp) != -1)
	{
		write(cfd,str,sizeof(str));
		memset(&str,0,BUFSIZ);
	}
	shutdown(cfd,SHUT_RDWR);
	read(cfd,str,sizeof(str));
	fclose(fp);
	close(lfd);
	close(cfd);


return 0;}
