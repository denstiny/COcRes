#include<iostream>
#include <type_traits>
using namespace std;

void max(int & a);
void swap(int *a);

int main(int argc,char *argv[])
{
	int a = 1;
	int s = 1;
	max(a);
	swap(&s);
	cout <<a << endl;
	cout << s << endl;
	return 0;
}
void max(int &  a)
{
	a += 2;
}
void swap(int *a)
{
	*a += 2;
}
