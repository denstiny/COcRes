#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 1,sum = 1;
	for(i = 1;i <= 10;i++)
	{
		sum = i + sum;
	}
	printf("%d\n",sum);
	int j;
	return 0;
}
