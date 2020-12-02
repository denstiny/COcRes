#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#define PORT 1234
#define MAXDATASIZE 100
int main(int argc,char *argv[])
{
    int sockfd;
    ssize_t send_num;
    ssize_t recv_num;
    char wel_msg[MAXDATASIZE];
    char cli_name[MAXDATASIZE];
    char recv_buf[MAXDATASIZE];
    char send_buf[MAXDATASIZE];
    struct hostent *he;
    struct sockaddr_in server;
    if(argc!=2)
    {
        printf("Usage:%s <IP Adress>\n",argv[0]);
        exit(1);
    }
    if((he=gethostbyname(argv[1]))==NULL)
    {
        printf("gethostbyname() failed.");
        exit(1);
    }
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        printf("socket() failed.");
        exit(1);
    }
    bzero(&server,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr=*((struct in_addr *)he->h_addr);
    if(connect(sockfd,(struct sockaddr *)&server,sizeof(server))==-1)
    {
        printf("connect() failed.");
        exit(1);
    }
    if ((recv(sockfd,wel_msg,MAXDATASIZE,0))==-1)
    {
        perror("[!] Receive welcome message fail.");
        exit(1);
    }
    wel_msg[sizeof(wel_msg)]='\0';
    printf("%s\n", wel_msg);
    printf("[*] Input client name:");
    scanf("%s",cli_name);
    if((send_num=send(sockfd,cli_name,MAXDATASIZE,0))==-1)
    {
        perror("send() error.");
        exit(1);
    }
    while(1)
    {
        printf("[*] Input string:");
        scanf("%s",send_buf);
        send_buf[strlen(send_buf)]='\0';
        if((send_num=send(sockfd,send_buf,MAXDATASIZE,0))==-1)
        {
            perror("send() error.");
            exit(1);
        }
        if((recv_num=recv(sockfd,recv_buf,MAXDATASIZE,0))==-1)
        {
            perror("recv() error.");
            exit(1);
        }
        printf("[>] Received reverse string:%s\n",recv_buf);
        if(!strcmp(recv_buf,"tiuq"))
        {
            break;
        }
    }
    close(sockfd);
    return 0;
}
