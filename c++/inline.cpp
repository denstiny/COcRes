#include<iostream>
using namespace std;
inline double square(double x)
{
	return x * x;
}
int main(int argc,char *argv[])
{
	double a,b;
	a = square(2);
	std::cout << a << std::endl;
	return 0;
}
