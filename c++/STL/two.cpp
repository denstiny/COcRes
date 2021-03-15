#include <iostream>
#include <memory>
#include <vector>
using namespace std;


int main(int argc,char *argv[]) {
	//vector<string> a  {"hello world"};
	vector<char*,allocator<char>> vec;
	vec.push_back("hello world");
	string a {"hello wolrd"};
	for(char* i:vec) {
		cout << i << endl;
	}
	return 0;
}
