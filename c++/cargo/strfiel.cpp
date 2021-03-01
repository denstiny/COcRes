#include <iostream>
#include <string>
using namespace std;

int main()
{
	int str[] = {1,2,3,4,5};
	//cout << (str == "1231") << endl;
	//  c++ string 可以直接进行字符串比较
	int i = 0,d = 0;
	for(int &s : str)
	{
		s++;
		//cout << str[i] << " " << i << endl;
		//i++;
		cout << ++i << d++ << endl;
	}
	return 0;
}
