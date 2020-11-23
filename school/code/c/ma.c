#include<stdio.h>
#define TRUE 0
#define FLAST 1
int Su_math(int number);
int main(int argc,char *argv[])
{
	int Math_Number[100] = {0};
	int Temp_n = 1,i,j = 1;
	for(int number = 2; number <= 100;number ++)
	{
		if(Su_math(number) == FLAST)
		{
			Math_Number[0]++;
			Math_Number[Temp_n] = number;
			Temp_n++;
		}
	}
	i = Temp_n;
	for(int number = 2; number <= 100;number ++)
	{
		if(Su_math(number) == TRUE)
		{
			Math_Number[Temp_n] = number;
			Temp_n++;
		}
	}
	printf("su shu zong shu%d\n",Math_Number[0]);
	for(j = 1;j < i;j++)
	{
		printf("hu shu ==>%d\t",Math_Number[j]);
	}
	puts("");
	for(int a = j;a < Temp_n;a ++)
		printf("su shu ==>%d\t",Math_Number[a]);
	puts("");

	return 0;
}
int Su_math(int number)
{
	for(int n = 2; n < number; n++)
		if(number%n == 0)
				return TRUE;
	return FLAST;
}
