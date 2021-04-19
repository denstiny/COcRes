#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "../include/http.h"

int main(int argc,char **argv) {
	cout << "Code run" << endl;
	/*
		父进程和子进程通信端口
	*/
	//int Parent_Fd[2],Son_Fd[2]; 

	Server test;
	while (1) {
	cout << "Accept" << endl;
	test.Accept();
	cout << "Client fd: " << test.client_fd << endl;

	cout << "Request head" << endl;
		test.Request_Head();    // 读取客户端发送的内容
		test.Request_headers(); // 返回客户端访问的数据
	}
	return 0;
}
