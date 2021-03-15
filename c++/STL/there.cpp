#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc,char *argv[]) {
	
	// 0~~ 
	vector<string> t;
	t.push_back("asdf'asdfasdf'");
	///vector<string>::iterator temp;
	///temp = t.begin();
	///while (temp != t.end()) {
	///	cout << temp->c_str() << endl;
	///	temp++;
	///}
	for (vector<string>::iterator str=t.begin(); str != t.end(); str++) {
		cout << str->c_str() << endl;
	}
	return 0;
}
