#include <cstdlib>
#include <string>
#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc,char **argv) {
	int fd[2];
	int lfd[2];
	pipe(fd);
	pipe(lfd);
	pid_t id= fork(); // 管道通信

	char lbuf[BUFSIZ] = "Ok,thinks!";
	char buf[BUFSIZ] = "hello wrold";
	if(id > 0) {
		sleep(1);
		read(fd[0], buf, sizeof(buf));
		cout << getpid() << ": " << buf << endl;
		write(lfd[1], lbuf,sizeof(lbuf));
	}else
	{
		write(fd[1], buf, sizeof(buf));
		sleep(1);
		read(lfd[0], lbuf, sizeof(lbuf));
		cout << getpid() << ": " << lbuf << endl;
	}
	return 0;
}
