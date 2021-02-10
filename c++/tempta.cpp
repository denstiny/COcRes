#include<iostream>
using namespace std;
template<class T1,class T2>
int ft(T1 &x,T2 &y)
{
	 int xpy = x + y;
	 return xpy;
}
int main(int argc,char *argv[])
{
	 int a = 1;
	 short b = 2;
	 int s = ft(a,b);
	 cout << s << endl;
	 return 0;
}
