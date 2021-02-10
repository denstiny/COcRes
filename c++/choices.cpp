#include <functional>
#include<iostream>
using namespace std;

template <class T>
T leasser(T a,T b);

int leasser (int a ,int b);

int main(int argc,char *argv[])
{
	 int a = 10,b = 3;
	 double x  = 12.3,y = 5.2;
	 cout << leasser(a,b) << endl; // use int
	 cout << leasser<int>(x,y) << endl; // use class
	 cout << leasser<int>(a,b) << endl; // use class
	 cout << leasser(x,y) << endl; // use class
	 return 0;
}


template <class T>
T leasser(T a,T b)
{
	 cout << "class" << endl;
	 return a-b;
}

int leasser (int a ,int b)
{
	 cout 	 << "int " << endl;
	 return a+b;
}

