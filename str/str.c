#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *str = malloc(sizeof(char)) ;
	fgets(str,30,stdin);
	puts(str);
	return 0;
}
