#include <iostream>
#include <string>
using namespace std;
int main()
{
	//string str;
	char str[10];
	//cin >> str;
	cin.getline(str,10);
	cout << str << endl;
	return 0;
}
