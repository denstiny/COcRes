#include <cstdio>
#include <csignal>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int argc,char **argv) {
	pid_t pid = fork();
	if(pid > 0) {

		cout << "父进程 " <<  getpid() << endl;
		if(kill(getpid()+1,0) == 0) {
			cout << "子进程存在" << endl;
			for(int i = 0; i < 3;i++) {
				sleep(1);
				cout << i << endl;
			}
			cout << "杀死子进程" << getpid()+1 << endl;
			pid_t s = getpid();
			kill(s+1, SIGKILL);

			for(int i = 0; i < 10;i++) {
				cout << "...." << endl;
				sleep(1);
			}
		}

	}
	if(pid == 0) {
		cout << "子进程 " <<  getpid() <<  endl;
		for(int i = 0; i < 10;i++) {
			sleep(1);
			cout << i << endl;
		}
	}
	return 0;
}
