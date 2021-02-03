#include <iostream>
using namespace std;
int* max()
{
	int *a = new int;
	*a = 10;
	return a;
}

int main()
{
	int *a;
	a = max();
	cout << *a << endl;
	delete a; 
	cout << *a << endl;
	return 0;
}
