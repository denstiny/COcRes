#include <iostream>
#include <string>
using namespace std;

int main(int argc,char *argv[]) {
	string str = "2254228017@qq.com";
	cout << "帐号： " << str.substr(0,str.find("@")) << " | " << str.substr(str.find("@")+1) << endl;
	return 0;
}
