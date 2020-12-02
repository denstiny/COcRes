#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 1234
#define BACKLOG 5
#define MAXDATASIZE 100
void pro_cli(int connfd,struct sockaddr_in client);
int main()
{
    int listenfd;
    int connfd;
    socklen_t client_len;
    pid_t pid;
    struct sockaddr_in server;
    struct sockaddr_in client;
    if((listenfd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        perror("socket() failed.");
        exit(1);
    }
    int opt=SO_REUSEADDR;
    setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    bzero(&server,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr.s_addr=htonl(INADDR_ANY);
    if(bind(listenfd,(struct sockaddr *)&server,sizeof(server))==-1)
    {
        perror("bind() failed.");
        exit(1);
    }
    if(listen(listenfd,BACKLOG)==-1)
    {
        perror("listen() failed.");
        exit(1);
    }
    client_len=sizeof(client);
    while(1)
    {
        if(((connfd=accept(listenfd,(struct sockaddr *)&client,&client_len))==-1))
        {
            perror("accept() failed.");
            exit(1);
        }
        if((pid=fork())>0)
        {
            close(connfd);
            continue;
        }
        else if(pid==0)
        {
            close(listenfd);
            pro_cli(connfd,client);
            exit(0);
        }
        else
        {
            printf("fork() failed.");
            exit(0);
        }
        close(listenfd);
    }
    return 0;
}
void pro_cli(int connfd,struct sockaddr_in client)
{
    ssize_t send_num;
    ssize_t recv_num;
    char send_buf[MAXDATASIZE];
    char recv_buf[MAXDATASIZE];
    char client_name[MAXDATASIZE];
    char wel_msg[]="[!] Welcome,you can input 'quit' to exit :)  ";
    printf("[!] You got a connection from client IP: <%s> PORT: <%d> \n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
    if((send(connfd,wel_msg,strlen(wel_msg),0))==-1)
    {
        perror("send welcome messages fail.");
        exit(1);
    }
    if((recv_num=recv(connfd,client_name,MAXDATASIZE,0))==-1)
    {
        perror("recv() failed.");
        close(connfd);
        return;
    }
    if(recv_num==0)
    {
        printf("[!] Client disconnected.\n");
        close(connfd);
    }
    client_name[recv_num-1]='\0';
    printf("[*] Client name: <%s> \n",client_name);
    while(1)
    {
        if((recv_num=recv(connfd,recv_buf,MAXDATASIZE,0))==-1)
        {
            perror("recv() error.");
            exit(1);
        }
        recv_buf[recv_num-1]='\0';
        printf("[*] Received string: '%s' from client: <%s> \n ",recv_buf,client_name);
        size_t len=strlen(recv_buf);
        for(int i=0; i<(len/2); ++i)
        {
            char tmp=recv_buf[i];
            recv_buf[i]=recv_buf[len-1-i];
            recv_buf[len-1-i]=tmp;
        }
        strcpy(send_buf,recv_buf);
        printf("[>] Send reverse string: '%s' to client: <%s> \n",send_buf,client_name);
        if((send_num=send(connfd,send_buf,MAXDATASIZE,0))==-1)
        {
            perror("send() error.");
            exit(1);
        }
        if(!strcmp(send_buf,"tiuq"))
        {
            printf("[!] Client <%s> have disconnected! \n",client_name);
            break;
        }
    }
    close(connfd);
    return;
}
