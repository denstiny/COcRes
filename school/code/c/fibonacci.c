/*********************************************************************************
*     File Name           :     fibonacci.c
*     Created By          :     chroot
*     Creation Date       :     [2020-11-17 10:35]
*     Last Modified       :     [2020-11-17 11:20]
*     Description         :      
**********************************************************************************/
#include<stdio.h>
int main()
{
	double Number[50] ={1,1};
	for(int s = 2;s < 50;s++)
		Number[s] = Number[s-1]+Number[s-2];
	for(int s = 0,sum = 0; s < 50; s++,sum ++)
	{
		printf("%-28.0f ",Number[s]);
		if(sum == 5)
		{
			sum = 0;
			printf("\n");
		}
	}
	return 0;
}

