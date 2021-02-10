#include<iostream>
#include <utility>
using namespace std;
decltype(1) var(decltype(1) a = 1);
int main(int argc,char *argv[])
{
	 
	 char a = var();
	 cout << a << endl;
	 decltype(1+0.2) s;
	 cout << typeid(s) << endl;
	 return 0;
}

decltype(1) var(decltype(1) a)
{
	 return a;
}
