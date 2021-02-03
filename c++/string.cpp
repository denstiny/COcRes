#include <cwchar>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string charstr {"hello wrold"} ;
	//getline(cin,charstr);
	//cin >> charstr;
	
	char *w = new char[234];
	cout << charstr << endl;
	cout << w << endl;

	return 0;
}
