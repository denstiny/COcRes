#include<stdio.h>
int main()
{
	int b = 1;
	for(int a=0;a<50;a++)
	{
		for(int sb = 0;sb < (50-a)/2;sb++)
		{
			printf("  ");
		}
		for(int i = 1;i<b;i++)
		{
			printf("*");
		}
		printf("\n");
		a+=2;
		b = 2*a-1;
	}
	return 0;
}
