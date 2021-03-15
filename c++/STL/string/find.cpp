#include <iostream>
using namespace std;

int main(int argc,char *argv[]) {
	
	string str;
	str = "123123";
	cout << str.find("2") + 1 << endl; // no find return -1
	cout << str.rfind("2")  << endl; // right -> lefit find 
	return 0;
}
