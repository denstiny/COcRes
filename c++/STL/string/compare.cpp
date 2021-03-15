#include <iostream>
#include <string>
using namespace std;

int main(int argc,char *argv[]) {
	string str1 = "hello world";
	string str2 = "hello";
	string str3 = "hello";
	if(str2.compare(str3) == 0) {
		cout << "string 等于" << endl;
	}else if (str2.compare(str3) > 0) {
		cout << "str1 > str 2" << endl;
	}else{
		cout << "str1 < str2" << endl;
	}
	return 0;
}
