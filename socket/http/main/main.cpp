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
		cout << "Waiting for the connection" << endl;
		clinetfd = accept(serverfd, (struct sockaddr *)&clinetaddr, &clientlen);
		cout << "Clinet: " << clinetfd  <<  " Send the connection request " << endl;
		if(head.requests_cliet_state(clinetfd, str)) {
			head.deal_cliet_requests(clinetfd,str);
		}
	}
	
	return 0;
}
