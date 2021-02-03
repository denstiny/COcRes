#include <iostream>
#include <vector>
#include <array>
using namespace std;
int main()
{
	cout << "<= start >=" << endl;

	char actor[30] ;
	short betsie[100];
	float chuck[13];
	long double dipsea[64];

	array<char, 30> actor1;
	array<short,100> betsie1;
	array<float, 13> chuck1;
	array<long double, 64> dipsea1[64];

	vector<int>	a(5);
	a = {1,2,3,4,5};
	cout << a[0] << " + " << a.back() << endl;


	return 0;
}
