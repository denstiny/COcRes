#include<iostream>
using namespace std;
void max(int *a);
int main(int argc,char *argv[])
{
	 int * a;
	 int *b;
	 cout << a << endl;
	 {
			a = new int;
			cout << a << endl;
			*a = 10;
	 }
	 cout << a << endl;
	 max(b);
	 cout << b << endl;
	 cout << *b << endl;
	 return 0;

}

void max(int *a)
{
	 a = new int;
	 *a = 10;
}

