#include <iostream>
using namespace std;
int main()
{
	double price[5] {3.99,10.99,6.87,7.99,8.49};
	for(double x:price)
		cout << x << endl;
	return 0;
}

