#pragma HTTP_H

#include <algorithm>
#include <thread>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ctime>
#include <unistd.h>
#include <cstring>
#include <error.h>
#include <netinet/in.h>
#include <fstream>
#include <string>
#include <vector>
#define PORT 9111
using namespace std;
#define FILEROOT "src/lib/"


#define Allow "HTTP/1.1 200 OK\r\nConnection: Keep-Alive\r\nContent-Type: %s\r\nSet-Cookie: PID=%d\r\n\r\n" 
#define Error "HTTP/1.1 404 OK\r\nContent-Type: %s\r\n\r\n"


class ServerHander;

class UserList {
	public:
		UserList();
		~UserList();
	public:
		/*
			Add user to list 
		*/
		bool AddUser(string username);
		/*
			Search user for user list 
		*/
		bool SearchUser(string username);
		/*
			delete user for user list
		*/
		bool DelectUser(string username);
		
};


class ServerHander {
	public:
		/*
			客户端访问的数据 
		*/
		bool client_work;
		string file_name;
		bool file_state;
		UserList user;
		

	public:
		/*
			创建套接字 
		*/
		int InitServer(void);
		/*
			返回状态码 
		*/
		bool requests_cliet_state(int &clientfd,string &str);
		/*
			返回客户端访问的数据
		*/
		bool deal_cliet_requests(int &clientfd,string &str);

		/*
			bool clinet list 
		*/
		bool Insert_work(int &clientfd,int pid);

		/*
			延迟包函数,如果超出时间没有发送请求,则关闭连接 
		*/
		
		friend void Stop_work(ServerHander &head,int clientfd);

	public: 
		ServerHander();
		~ServerHander();
};

void Stop_work(ServerHander &head,int clientfd);
