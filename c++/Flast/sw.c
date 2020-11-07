#include<stdio.h>
int main()
{
	char a;
	scanf("%s",&a);
	switch(a)
	{
		case 'm':printf("星期一 \n");break;
		case 's':printf("星期二 \n");break;
		case 't':printf("星期三 \n");break;
		case 'w':printf("星期四 \n");break;
		case 'f':printf("星期五 \n");break;
		case 'sw':printf("星期六 \n");break;
		default:printf("星期七 \n");break;
	}
}
