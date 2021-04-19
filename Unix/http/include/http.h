#include <iostream>
#pragma INCLUDE_HTTP_H
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888
#define src "src"
#define Allow "HTTP/1.1 200 OK\r\nConnection: Keep-Alive\r\nContent-Type: %s\r\n\r\n" 
#define Error "HTTP/1.1 404 OK\r\nContent-Type: %s\r\n\r\n"
using namespace std;
/*

	 项目: tcp 协议 实现 http 服务器
	 思路:


                                                +--------------+
                                                |     main     |
                                                +--------------+
                                                        |
                                                        |
                                                        |
                                   +-------------+      |          +------------+
                                   |   PID > 0   |------+----------|  PID = 0   |
                                   +-------------+                 +------------+
                                         |                               |
                                         |                               |
                                         |                               |
                                         |                               |
                                +--------------+               +-------------------+           +------------------+
                                |接受客户端请求| -> 创建子进程 |  处理客户端数据   | <- --- -> |    创建新线程    |
                                +--------------+               +-------------------+           +------------------+
                                         |                                |
                                         |                                |     +---------------------------------------------------------+
                                         |                                |     |                                                         |
                                         |                                |     |     启动心跳包,判断客户端是是否活跃,否则终止客户端      |
                       +---------------------------------+                |     |                                                         |
                       |接收子进程消息,添加或删除相应节点|                |     +---------------------------------------------------------+
                       +---------------------------------+                |
                                                       +-----------------------------------------+
                                                       |        发送客户端状态到父进程           |
                                                       +-----------------------------------------+




*/



class ClassHttp {
	public:
	/*
		创建套接字 
	*/
		int server_fd,client_fd;
		struct sockaddr_in serveraddr;
	public:
		int Accept();
	public:
		ClassHttp();
		~ClassHttp();
};


class Server :public ClassHttp {
	public:
		string clientState;
		string fileName;
	public:
		/*
			读取客户端请求 
		*/
		bool Request_Head();
		bool Request_headers();

	public:
		Server();
		~Server();
};
