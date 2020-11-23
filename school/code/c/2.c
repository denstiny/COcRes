/*********************************************************************************
*     File Name           :     2.c
*     Created By          :     chroot
*     Creation Date       :     [2020-11-17 11:33]
*     Last Modified       :     [2020-11-17 11:35]
*     Description         :      
**********************************************************************************/
#include<stdio.h>
int  main()
{
	int a = 2,b = 1;
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a ==>%d\tb ==>%d\n",a,b);
	return 0;
}


