#include<stdio.h>
#define SIze 5
int main(){
	int number[SIze],i,j ;
	for(i = 0;i < SIze;i++)
		scanf("%d",&number[i]);
	for(i = 0;i<SIze ;i++)
	{
		for(j = 0 ; j < SIze ; j ++)
		{
			if(number[i] > number[j] )
			{
				number[i] = number[i]^number[j];
				number[j] = number[i]^number[j];
				number[i] = number[i]^number[j];
			}
		}
	}
	i = 0;
	while(i!=SIze)
	{
		printf("map > %d\n",number[i]);
		i++;
	
	}
	return 0;
}
