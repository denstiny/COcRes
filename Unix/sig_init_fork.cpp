#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <sys/wait.h>
#include <wait.h>
#include <csignal>
using namespace std;

void sig_init(int sig) {
	printf("child to %d\n",sig);
	wait(0);
}


void out(int i) {
	for(int n = 0;n < i;n++) {
		cout << getpid() << " to " << n << endl;
		sleep(2);
	}
}

int main(int argc,char **argv) {
	if(signal(SIGCHLD, sig_init) == SIG_ERR) {
		perror("signal error");
		exit(0);
	}

	pid_t pid = fork();
	if(pid == 0) {
		out(10);
	}if(pid > 0) {
		out(100);
	}

	return 0;
}
