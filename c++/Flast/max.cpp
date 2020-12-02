#include <iostream>
using namespace std;
int func(int a,int b = 20,int c = 20)
{
	return a+b+c;
}


int main()
{
	int a=2,b,c=3;
	cout << func(a,10,20) << endl;
	return 0;
}
