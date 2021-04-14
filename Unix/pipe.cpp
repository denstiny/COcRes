#include <cstdio>
#include <string>
#include <iostream>
#include <csetjmp>
#include <cstdlib>
#include <cstring>
#include <strings.h>
#include <unistd.h>
using namespace std;
#define BUF_SIZE 30
int main(int argc, char ** args) {
	int fd[2] = {0};
	pipe(fd);
	pid_t id = fork();
	string str("hello world!");
	string strn("The world would like to welcome you!");
	char strin[1024];
	bzero(strin, sizeof(strin));


	// 单向通信
//	cout << "单向通信" << endl;
//	if(id == 0) {
//		write(fd[1], str.c_str(), str.length());
//	}else {
//		read(fd[0],strin , sizeof(strin));
//		cout << strin << endl;
//	}
//
	// 双向通信
	cout << "双向通信" << endl;
	if(id > 0) {
		bzero(strin, sizeof(strin));
		write(fd[1], str.c_str(), str.length());
		sleep(2);
		read(fd[0], strin, sizeof(strin));
		cout << strin << endl;
	}
	else {
		bzero(strin, sizeof(strin));
		read(fd[1], strin, sizeof(strin));
		cout << strin << endl;
		write(fd[0], strn.c_str(), strn.length());
		sleep(3);
	} 
 /*   int fds[2];
    char str1[] = "Who are you?";
    char str2[] = "Thank you for your message!";
    char buf[BUF_SIZE];
    pid_t pid;
 
    pipe(fds);
    pid = fork();
    if (pid == 0)
    {
        write(fds[1],str1,sizeof(str1));        //传输数据
        sleep(2);                               //睡眠两秒，避免被下一行的read函数读取了数据。
        read(fds[0],buf,BUF_SIZE);
        printf("Child proc output: %s \n",buf);    //接收数据
    }
    else 
    {
        read(fds[0],buf,BUF_SIZE);                //接收数据
        printf("Parent proc output: %s \n",buf);
        write(fds[1],str2,sizeof(str2));        //传输数据
        sleep(3);        //睡眠,防止父进程在子进程输出之前结束，可删除
            //不理解的话你注释掉这个sleep体会一下就知道了
    }
	*/
	return 0;
}
