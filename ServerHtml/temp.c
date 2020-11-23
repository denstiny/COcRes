/*********************************************************************************
*     File Name           :     temp.c
*     Created By          :     chroot
*     Creation Date       :     [2020-11-17 23:19]
*     Last Modified       :     [2020-11-18 00:07]
*     Description         :     fopen 
**********************************************************************************/

#include<stdio.h>
int main(int argc,char *argv[])
{
	char str[BUFSIZ] = {0};
	FILE *fp = fopen("./index.html","r");
	int n;
	while(1)
	{
		n = fread(str,1,sizeof(str),fp);
		printf("%d\n",n);
		if(n != 0)
			break;
	}
	return 0;
}
