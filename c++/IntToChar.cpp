#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc,char **argv) {
	char buf[100];
	sprintf(buf, "hello world %d",10);
	cout << buf << endl;

	string buf1;
	buf1 = to_string(10);
	cout << buf1 << endl;
	return 0;
}
