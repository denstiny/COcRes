#include <iostream>
int mian()
{
	static char *a[10];
	a[10] = { "asdf\0" };
	return 0;
}
