#include <cstdio>
#include <string>
#include <iostream>
using namespace std;


int main(int argc,char *argv[]) {
	string s = "I'm play Game: ";
	string st = "CTF LOL";
	s.append(st,0,3);
	string sta;
	// 			开始位置， 结束位置
	cout << s << endl;
	sta = s + st;
	cout << sta << endl;
	return 0;
}
