/**
 * File              : main/main.cpp
 * Author            : denstiny <2254228017@qq.com>
 * Date              : 04.04.2021
 * Last Modified Date: 04.04.2021
 * Last Modified By  : denstiny <2254228017@qq.com>
 */
#include "../include/http.hpp"
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iterator>
#include <strings.h>
#include <thread>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

int main( int argc, char *argv[] ) {
	ServerHander head;
	int serverfd = head.InitServer(),clientfd  = -1;
	struct sockaddr_in clinetaddr;
	bzero(&clinetaddr, sizeof(clinetaddr));
	socklen_t clientlen = sizeof(clinetaddr);
	cout << "等待连接" << endl;
	//pid_t pid = fork();
	while (1) {
		/*
		   开始执行任务
	    */

		/*
			利用多进程内存不会共享原理,调用多线程来做心跳包,当客户端接收到请求,则创建一个新的进程,来处理
			客户端数据,当客户端数据合法,则作出回应,并新建一个线程,在有效时间内,客户端没有继续发送请求则
			断开连接
		*/
		pid_t pid = fork();
		if(pid > 0) {  		  // 主进程负责接受请求
			if(( clientfd = accept(serverfd, (struct sockaddr *)&clinetaddr, &clientlen)  ) != -1) {
				//if(head.Insert_work(clinetfd, clinetaddr.sin_addr.s_addr)) {
					cout << "客户端: " << clientfd  << "申请连接"<< endl;
				//}
				//else
			//		cout << "客户端: " << clinetfd << "重复申请访问拒绝" << endl;;
			}else {
				perror("clinetfd error");
				exit(1);
			}
			
		}

		if(pid == 0) { 		  // 客户端负责处理请求
		//	shutdown(serverfd,SHUT_WR);
			close(serverfd);  // 子进程不需要服务端套接字,故关闭
			string str;
			thread th(Stop_work,ref(head),clientfd);
			/*
				判断 客户端是否访问合法的数据,如果合法则作出回应 否则关闭连接
			*/
			while(head.requests_cliet_state(clientfd, str)) {  
				head.client_work = true;
				if(!head.deal_cliet_requests(clientfd,str)) {
					shutdown(clientfd,SHUT_RDWR);
					close(clientfd);
					head.client_work = false;
					break;
				}
				str.clear();
				cout << "完成请求" << endl;
			}
			th.join();
			exit(1);
		}
	}

	return 0;
}
