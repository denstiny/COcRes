#include<stdio.h>
#define Size 5
int main()
{
	puts("Go");
	int number[Size],i,j,k;
	for(i = 0;i < Size;i++)
		scanf("%d",&number[i]);
	i = 0;
	for(i = 0;i < Size ; i ++)
	{
		if(number[i] > number[i+1] && i < Size)
		{
			number[i+i] = number[i]^number[i+1];
			number[i] = number[i]^number[i+1];
			number[i+1] = number[i]^number[i+1];
		}
	}
	i = 0;
	while(i!=Size)
	{
		printf("map > %d\n",number[i]);
		i++;
	}
	return 0;
}
