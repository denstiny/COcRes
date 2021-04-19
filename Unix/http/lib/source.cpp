#include "../include/http.h"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void Print() {
	cout << "----------------------------------------------------------------------" << endl;
}


ClassHttp::ClassHttp() {
	cout << "Create ClassHttp" << endl;
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	int option = 1;
	setsockopt(server_fd, SOL_SOCKET,SO_REUSEADDR ,&option, sizeof(option));

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(PORT);
	serveraddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(server_fd, (struct sockaddr *)&serveraddr, sizeof(serveraddr))) {
		perror("Bind PORT error");
		exit(0);
	}
	listen(server_fd, 100);
	cout << "Create ClassHttp Ok!" << endl;
}

/*
	接收客户端请求
*/
int ClassHttp::Accept() {
	cout << "listen ...." << endl;
	socklen_t client_len = sizeof(server_fd);
	client_fd = accept(server_fd, (struct sockaddr *)&serveraddr, &client_len);
	Print();
	if(client_fd == -1) {
		perror("Accept error:");
		exit(1);
	}
	return client_fd;
}


ClassHttp::~ClassHttp() {
}


bool Server::Request_Head() {
	char buf[BUFSIZ],file_name[100];
	fileName = src;
	if(read(client_fd, buf, sizeof(buf)) < 0) {
		perror("read error");
		exit(1);
	}
	cout << "客户端发送请求==> \n" << buf;
	/*
		GET / HTTP/1.1
	*/
	sscanf(buf,"GET %s HTTP",file_name);

	while(1){
		if(strstr(file_name, "index.html")) {
			clientState = "text/html";
			fileName += "/index.html";
			break;
		}
		if(strstr(file_name,".png")) {
			clientState = "image/png";
			fileName += file_name;
			break;
		}
		if(strstr(file_name,".jpg")) {
			clientState = "image/jpg";
			fileName += file_name;
			break;
		}
		fileName += "/index.html";
		break;
		cout << "while" << endl;
	}

	fstream obs(fileName,ios::in);
	if(!obs.is_open()) {
		cout << "数据访问不存在" << endl;
		char _state[BUFSIZ];
		sprintf(_state, Allow,clientState.c_str());
		clientState = _state;
		write(client_fd, clientState.c_str(), clientState.length());
		cout << fileName << endl;
		return false;
	}
	cout << "客户端访问 -> " << fileName << endl;
	obs.close();
	
	char _state[BUFSIZ];
	sprintf(_state, Allow,clientState.c_str());
	clientState = _state;
	return true;
}

bool Server::Request_headers() {
	string file = clientState,_file;
	fstream obs(fileName,ios::in);
	while (!obs.eof()) {
		file += obs.get();
	}
	obs.close();
	cout << "服务端返回 -> " << fileName << endl;
	write(client_fd, file.c_str(), file.length()-1);
	Print();
	return false;
}

Server::Server() {
	fileName = src;
}

Server::~Server() {
}

