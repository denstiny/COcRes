/*********************************************************************************
*     File Name           :     sprintf.c
*     Created By          :     chroot
*     Creation Date       :     [2020-11-17 20:41]
*     Last Modified       :     [2020-11-17 20:48]
*     Description         :     Sprintf 测试 
**********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main()
//sprintf 
{
	char *str =(char *) malloc(sizeof(char));
	sprintf(str,"%d",123);
	while(*str != '\0')
	{
		printf("%d => %c\n",*str,*str);
		str+=1;
	}
	return 0;
}
