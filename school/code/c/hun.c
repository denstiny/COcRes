#include<stdio.h>
void Print(int number[3][3]);
int main()
{
	int Numebr[3][3] = {
		{1,2,3},
		{5,6,7,},
		{9,10,11}
	};
	int Sum_Number[3][3] = {0};
	for(int a = 0; a < 3;a++)
	{
		for(int b = 0;b < 3;b++)
		{
			Sum_Number[b][a] = Numebr[a][b];
		}
	}
	puts("转换前==>");
	Print(Numebr);
	puts("转换后==>");
	Print(Sum_Number);
}

void Print(int number[3][3])
{
	for(int a = 0; a < 3; a ++)
	{
		for(int b = 0; b < 3; b ++)
		{
			printf("%d\t",number[a][b]);
		}
		printf("\n");
	}
}
