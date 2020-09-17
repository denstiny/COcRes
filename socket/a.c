/*********************************************************************************
*     File Name           :     a.c
*     Created By          :     Aero
*     Github              :     Aero denstiny
*     Creation Date       :     [2020-05-21 21:38]
*     Last Modified       :     [2020-05-21 21:50]
*     Description         :     ce shi
**********************************************************************************/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/in.h>
#include<stdio.h>
int main()
{
	char a[] = "127.0.0.1";
	printf("%d\n",inet_addr(a));
	printf("%d\n",htons(INADDR_ANY));
	return 0;
}
