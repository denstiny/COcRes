#include <iostream>
#include <string>
using namespace std;
int main(int argc,char *argv[])
{
	
	string str;
	cin >> str;
	for(int i =str.size()-1; i >= 0;i-- )
		cout << str[i];
	return 0;
}
