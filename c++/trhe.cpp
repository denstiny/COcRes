#include<iostream>
#include <type_traits>
using namespace std;

template<typename t>
void Swap(t &a,t &b);

struct job
{
	 int a;
};

template <> void Swap<int>(int &a,int &b);

int main(int argc,char *argv[])
{
	 
	return 0;
}

template <> void Swap<int>(int &a,int &b)
{
	 cout << "a -=> " << a << " | " << "b -=> " << b << endl;
}
