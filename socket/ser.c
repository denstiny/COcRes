/*********************************************************************************
*     File Name           :     ser.c
*     Created By          :     Aero
*     Github              :     Aero denstiny
*     Creation Date       :     [2020-05-21 16:41]
*     Last Modified       :     [2020-05-21 21:44]
*     Description         :     serv.c 
**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#define PORT 1234
#define MAXNUMCLINET 20
#define MAXDATASIZE 100
int main()
{
    int socketfd,bindfd,listenfd,connectfd,opt=SO_REUSEADDR;
    ssize_t recv_num,send_num;
    struct sockaddr_in server,client;
    socklen_t addrlen;
    char recv_buf[MAXDATASIZE],send_buf[MAXDATASIZE];
    char wel[]="[*] Welcome! You can input 'quit' to exit:)";
    if((socketfd=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        perror("socket() error.");
        exit(1);
    }
    setsockopt(socketfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    bzero(&server,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr.s_addr=htonl(INADDR_ANY);
    if((bindfd=bind(socketfd,(struct sockaddr *)&server,sizeof(server)))==-1)
    {
        perror("bind() error.");
        exit(1);
    }
    if((listenfd=listen(socketfd,MAXNUMCLINET))==-1)
    {
        perror("listen() error.");
        exit(1);
    }
    if((connectfd=accept(socketfd,(struct sockaddr *)&client,&addrlen))==-1)
    {
        perror("accept() error.");
        exit(1);
    }
    if((send(connectfd,wel,sizeof(wel),0))==-1)
    {
        perror("send welcome messages fail.");
        exit(1);
    }
    printf("You got a connection from client IP:%s, PORT:%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
    while(1)
    {
        if((recv_num=recv(connectfd,recv_buf,MAXDATASIZE,0))==-1)
        {
            perror("recv() error.");
            exit(1);
        }
        printf("[*] Received string:%s\n",recv_buf);
        size_t len=strlen(recv_buf);
        for(int i=0; i<(len/2); ++i)
        {
            char tmp=recv_buf[i];
            recv_buf[i]=recv_buf[len-1-i];
            recv_buf[len-1-i]=tmp;
        }
        strcpy(send_buf,recv_buf);
        printf("[>] Send reverse string:%s\n",send_buf);
        if((send_num=send(connectfd,send_buf,MAXDATASIZE,0))==-1)
        {
            perror("send() error.");
            exit(1);
        }
        if(!strcmp(send_buf,"tiuq"))
        {
            close(connectfd);
            break;
        }
    }
    close(connectfd);
    close(listenfd);
    return 0;
}

