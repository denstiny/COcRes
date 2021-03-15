#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main(int argc,char *argv[]) {
	string str = "hello";

	for(int i=0;i < str.size();i++) {
		cout << str[i] << endl;
	}

	for(int i = 0; i < str.size();i++) {
		cout << str.at(i) << " ";
	}
	cout << endl;

	char st[] = "world";
	for(int i = 0; i < strlen(st);i++) {
		if(i > str.size()) {
			str +=  st[i];
		}else
			str.at(i) = st[i];
	}
	cout << str << endl;
	return 0;
}
