#include<iostream>
using namespace std;
template<typename Anytype>
void Swap(Anytype &a,Anytype &b);
int main(int argc,char *argv[])
{
	int i = 10;
	int b = 1;
	Swap(i, b);
	cout << "a -=>" << i << "b -=>" << b << endl;
	return 0;
}

template<typename Anytype>
void Swap(Anytype &a,Anytype &b)
{
	Anytype temp;
	temp = a;
	a = b;
	b = temp;
}
