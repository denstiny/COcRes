#include<stdio.h>
int main()
{
	int a=0,b = 1 ,i =0,s=25;
	while(a < 50)
	{
		for(int sb = 0;sb < a/2;sb++)
		{
			printf("\t");
		}
		while(i < b)
		{
			printf("*");
			i+=2;
		}
		b = 2*a-1;
		i=1;
		printf("\n");
		a+=2;
	}
	return 0;
}
