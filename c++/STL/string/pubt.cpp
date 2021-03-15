#include <iostream>
#include <string>
using namespace std;

/*
   string 容器
   */

int main(int argc,char *argv[]) {
	string s1; // 默认构造
	const char * str = "hello world";
	string s2(str);

	cout << s2 << endl;
	string s3(s2);

	cout << s3 << endl;
	string s4(10,'a');

	cout << s4 << endl;
	return 0;
}
