#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char str[4][20];
	char str1[4][3];
	strcpy(str[0],"Hello world!");
	strcpy(str[1],"We conputer");
	strcpy(str[2],"Please come on");
	int a = 0;
	while( a  < 4 )
	{
		printf("%s\n",str[a]);
		a ++;
	}
	return 0;
}
