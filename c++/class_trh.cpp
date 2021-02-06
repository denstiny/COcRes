#include<iostream>
using namespace std;
template <class t>
t Add(t a,t b);
int main(int argc,char *argv[])
{
	 int a = 1;
	 int b = 2;
	 a = Add(a,b);
	 cout << a << b << endl;
	 return 0;
}

template <class t>
t Add(t a,t b)
{
	 cout << "Class" << endl;
	 return a+b;
}
