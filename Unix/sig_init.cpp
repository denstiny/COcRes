#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <csignal>
#include <sys/wait.h>
using namespace std;
void sig_init(int) {
	printf("\nexit %d\n ",getpid());
	exit(0);
}
int main(int argc,char **argv) {
	if(signal(SIGINT, sig_init) == SIG_ERR) {
		perror("signal error");
		exit(0);
	}
	while (1) {
		cout << "SIGNAL" << endl;
		sleep(1);;
	}
	return 0;
}
