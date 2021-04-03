/**
 * File              : src/http.cpp
 * Author            : denstiny <2254228017@qq.com>
 * Date              : 04.04.2021
 * Last Modified Date: 04.04.2021
 * Last Modified By  : denstiny <2254228017@qq.com>
 */

#include "../include/http.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <strings.h>
#include <unistd.h>

/*
	创建套接字 

	Create a socket
*/
int ServerHander::InitServer(void) {
	int fd = socket(AF_INET, SOCK_STREAM, 0);

	// 使 fd可以重用 这是错误的,即使这是错误的
	int option = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));


	struct sockaddr_in serveraddr;
	bzero(&serveraddr, sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(PORT);
	serveraddr.sin_addr.s_addr = INADDR_ANY;


	if(bind(fd, (struct sockaddr *)&serveraddr,sizeof(serveraddr) ) == -1) {
		perror("绑定端口错误！");
		exit(1);
	}

	listen(fd, 100);

	return fd;
}


// 处理客户端数据
bool ServerHander::deal_cliet_requests(int clientfd,string &str) {
	fstream obs(file_name,ios::in);
	//cout << "str ==> " << str  << " <==="<< endl;
	if(!obs.is_open()) {
		cout << "对数据的访问不存在：" << file_name << endl;
		return false;
	}
	while(!obs.eof()) {
		str += obs.get();
	}
	obs.close();
	if(file_name.rfind("html") != file_name.npos)
		cout << "返回数据 ==> \n " <<  str  << "\n<==" <<endl;
	write(clientfd, str.c_str(), str.length()-1);
	
	return true;
}


bool ServerHander::requests_cliet_state(int clientfd,string &str) {
	
	char mime[100],buffer[BUFSIZ] = {0},file_name[100];
	string Fname = FILEROOT;

	int nreed = read(clientfd,buffer,sizeof(buffer));
	/*
		读取客户端发送的数据,并返回成功的状态码 
		如果客户访问的数据不存在则返回访问404

		Read the client sends data is failed
		If the client access 404 data does not exist

	*/
	sscanf(buffer,"GET /%s",file_name);

	if(strstr(file_name,".html")) {
		strcat(mime,"text/html");
	}
	if(strstr(file_name,".png")) {
		strcat(mime, "image/png");
	}
	else if(strstr(file_name,".jpg")) {
		strcat(mime,"image/jpg");
	}
	char temp_str[BUFSIZ] = {0};

	Fname += file_name;
	fstream obs(Fname,ios::in);

	if(!obs.is_open()) {

		sprintf(temp_str,Error,mime);
		str = temp_str;
		write(clientfd,str.c_str(),sizeof(str));
		cout << "数据访问不存在: " << file_name << endl;
		obs.close();
		close(clientfd);
		file_state = false;
		return false;
	}else {
		sprintf(temp_str,Allow,mime);
		str = temp_str;
		file_state = true;
		this->file_name = Fname;
		obs.close();
		return true;
	}
}
