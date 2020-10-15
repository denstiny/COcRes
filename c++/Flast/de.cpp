//引用调用
#include<iostream>
using namespace std;
int main()
{
	int i;
	int &r = i;
	i = 8;
	cout << "Value of I:" << i << endl;
	cout << "Balue R:" << r << endl;
	
return 0;}
