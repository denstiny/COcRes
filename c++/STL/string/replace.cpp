#include <iostream>
#include <string>
using namespace std;

int main(int argc,char *argv[]) {
	string str = "asdfaaasd";
	// 从1 号位置起，3个字符替换为 111
	str.replace(str.find("d"),3,"1");
	cout << str << endl;
	
	return 0;
}
