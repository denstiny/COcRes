#include <iostream>
union ema
{
	int a ;
	char s;
}a;
int main()
{
	a.a = 1;
	a.s = '1';
	std::cout << a.a << " " << a.s << std::endl;
	return 0;
}
