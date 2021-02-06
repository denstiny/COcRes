#include<iostream>
#include <type_traits>
using namespace std;

void Swap(float &a,float &b);
template<typename t>

void Swap(t &a,t &b);

struct job
{
	 int a;
};

template <> void Swap<int>(int &a,int &b);


int main(int argc,char *argv[])
{
	 
	 float a = 1;
	 float b = 2;
	 Swap(a, b);
	return 0;
}

template <> void Swap<int>(int &a,int &b)
{
	 cout << "a -=> " << a << " | " << "b -=> " << b << endl;
}

template<typename t> void Swap(t &a,t &b)
{
	 cout << "template typename" << endl;
}

void Swap(float& a,float &b)
{
	 cout << "Void Swap" << endl;
}
