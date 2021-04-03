/**
 * File              : main/main.cpp
 * Author            : denstiny <2254228017@qq.com>
 * Date              : 04.04.2021
 * Last Modified Date: 04.04.2021
 * Last Modified By  : denstiny <2254228017@qq.com>
 */
#include "../include/http.hpp"
#include <algorithm>
#include <csignal>
#include <cstdio>
#include <iterator>
#include <strings.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

int main( int argc, char *argv[] ) {
	ServerHander head;
	int serverfd = head.InitServer(),clinetfd;
	struct sockaddr_in clinetaddr;
	bzero(&clinetaddr, sizeof(clinetaddr));
	socklen_t clientlen = sizeof(clinetaddr);

	string str;

	while (1) {
		cout << "等待连接" << endl;
		clinetfd = accept(serverfd, (struct sockaddr *)&clinetaddr, &clientlen);
		cout << "客户端: " << clinetfd  <<  " 发送连接请求" << endl;
		if(head.requests_cliet_state(clinetfd, str)) {
			head.deal_cliet_requests(clinetfd,str);
		}
	}
	
	return 0;
}
