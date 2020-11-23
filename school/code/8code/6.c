#include<stdio.h>
#define max 10
void Print(int number[][max]);
int main()
{
	int number[max][max] = {0};
	number[0][0]  = 1;
	for(int i = 1; i < max;i++)
	{
		for(int k = 0;k<max;k++)
		{
			if(k == 0)
			{
				number[i][k] = 1;
				continue;
			}
			number[i][k] = number[i-1][k]+number[i-1][k-1];
		}
	}
	Print(number);
	return 0;
}
void Print(int number[][max])
{
	for(int i = 0;i < max; i++)
	{
		for(int k = 0;k < i+1;k++)
		{
			printf("%d ",number[i][k]);
		}
		puts("");
	}
}
