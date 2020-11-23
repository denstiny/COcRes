/*********************************************************************************
*     File Name           :     mar.c
*     Created By          :     chroot
*     Creation Date       :     [2020-11-17 09:55]
*     Last Modified       :     [2020-11-17 10:09]
*     Description         :      
**********************************************************************************/

#include<stdio.h>
int main()
{
	printf("float ==>%ld\nint ==>%ld\nlong ==>%ld",sizeof(float),sizeof(int),sizeof(long));
	int arg[10] = {0};
	for(int s =0 ;s < 10 ;s++)
		arg[s] = s;
	for(int n  = 0;n < 10;n++)
	{
		printf("%d\n",arg[n]);
	}
}
