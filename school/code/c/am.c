#include<stdio.h>
int main()
{
	int *a,b = 7;
	char *c , str[] = {'a','b'};
	a = &b;
	c = &str[1];
	printf("%d\n%c\n",*a,*c);
	return 0;
}
