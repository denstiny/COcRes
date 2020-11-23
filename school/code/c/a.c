#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "stdio.h"
int main(int argc,char *argv[])
{
	int i ,j,k;
	for (i = 1; i <= 5; i++)
	{
		printf("%d\n",i);
		for(j = 1;j <= 5-i;j++)
			printf(" ");
		for(j = 1;j <= 2*i-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
