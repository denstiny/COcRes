#include <iostream>
#include <string>
using namespace std;

int main(int argc,char *argv[]) {
	string str = "acbdef";

	string subStr = str.substr(0,3);
	cout << subStr << endl;
	return 0;
}
