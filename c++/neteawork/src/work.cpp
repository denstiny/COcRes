/*
 *  music：网易云音乐
 *  
 *
 * */
#include<iostream>
#include <netdb.h>
#include <netinet/in.h>
#include<string>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

#define Port 80

int MakeSocket(const string host) {
	int tcp_socket = socket(AF_INET,SOCK_STREAM,0);
	
	return tcp_socket;
}

int main(int argc,char *argv[]) {

	string url = "baidu.com";  // 地址

	struct hostent *host_ip;
	struct sockaddr_in cline_server;

	//string HostUrl, PagePath;

	host_ip = gethostbyname(url.c_str());  // 获取ip地址

	cout << host_ip->h_name << endl << host_ip->h_addr_list << endl << host_ip->h_addrtype << endl << host_ip->h_aliases << endl << host_ip->h_length<< endl << host_ip->h_addr << endl;


	bzero(&cline_server, sizeof(cline_server));

	cline_server.sin_family = AF_INET;
	cline_server.sin_port = htons(Port);
	cline_server.sin_addr.s_addr = ((struct in_addr *) (host_ip->h_addr))->s_addr;  //  转换 字节序列


	int sfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sfd == -1){
		cout << "create sfd crror" << endl;
		exit(1);
	}


	string name = "/img/bdlogo.gif";
  //string request = "GET " + name + " HTTP/2.0\r\nHost:" + url + "\r\nConnection:Close\r\n\r\n"; // 请求头
	string request;
	request  = "GET www.baidu.com HTTP/1.1\r\n";
	request += "Host: " + url + "\r\n";
	request += "Accept: */*\r\n";
	request += "User-Agent: Mozilla/4.0(compatible)\r\n";
	request += "connection:Keep-Alive\r\n";
	request += "\r\n";
	int ret = connect(sfd,(const sockaddr *)&cline_server,sizeof(cline_server));

	if(ret == -1){
		cout << "connect error" << endl;
		exit(1);
	}

	ret = send(sfd,request.c_str(),request.size(),0);
	if(ret == -1){
		cout << "send crror" << endl;
		exit(1);
	}

	char c;
	while (recv(sfd, &c,1, 0) ) {
		cout << c;
}	

	return 0;
}
