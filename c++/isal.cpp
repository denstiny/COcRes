#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main()
{
	char s;

	while (isalpha(s=cin.get())) {
		cout << s;
	}
	//while((s = cin.get()) != '\n' and isalpha(s))
	//	cout << s;
	return 0;
}
