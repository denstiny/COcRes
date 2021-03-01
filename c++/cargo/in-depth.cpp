#include<iostream>
using namespace std;
const double *f1(const double ar[] ,int n);
const double *f2(const double [] ,int n);
const double *f3(const double * ,int n);

int main(int argc,char *argv[])
{
	const double *(*p1)(const double *,int) = f1;
	const double av[3] {1,2,3};
	cout << (*p1)(av,3) << " : " << *(*p1)(av,3) << endl;
	auto pd = f2;
	cout << pd(av,3) << " : " << *pd(av,3) <<  endl;
	return 0;
}

const double *f1(const double ar[] ,int n)
{
	return ar;
}
const double *f2(const double ar[] ,int n)
{
	return ar+1;
}
const double *f3(const double *ar ,int n)
{
	return ar+2;
}
