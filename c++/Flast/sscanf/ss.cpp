#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

int main(int argc,char **argv) {
	string buf,tempbuf;
	string str;
	fstream obs("tea",ios::in);
	while (!obs.eof()) {
		getline(obs,tempbuf);
		tempbuf += '\n';
		buf += tempbuf;
	}
	cout << buf ;
	int s = buf.find_last_of("Cookie");
	cout << "Cookie:" << s << endl;
	string st = buf.substr(buf.find("Cookie"));
	sscanf(st.c_str(),"Cookie: PID=%s",str.c_str()); 
	cout << str << endl;
	return 0;
}
