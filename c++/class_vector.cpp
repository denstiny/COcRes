#include <cstdio>
#include <iostream>
#include <vector>
#include <array>
using namespace std;
int main()
{
	int n ;
	vector<int> a(2);
	array<int,1> s;
	a[0] = 1;
	a.insert(a.end(),2);
	s[0] = 2;
	cerr << "vi[0]  " << a[0] << endl
		<< "vi[1]  " << a[1] << endl
		<< "a[0]  " << a[0] << endl;
	return 0;

}
