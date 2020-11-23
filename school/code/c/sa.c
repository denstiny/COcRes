#include<stdio.h>
int str(char **c,int a);
int main()
{
	int a;char *c;
	a = str(&c,a);
	printf("%d==>%c\n",a,*c);
	return 0;
}
int str(char **c,int a)
{
	char s = 'A';
	**c = s;
	return 100;
}
