#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;

int main(int argc,char **argv) {
	pid_t dp = fork();
	
	int i = 0;
	int s = 0;
	/*
		多个进程中,不同进程的资源是独立的 
	*/
	while (i < 10) {

		if(dp > 0)  {
			i++;
		}
		else
			i++;
		cout << i << endl;
	}
	return 0;
}
