#include<stdio.h>
int main()
{
	unsigned int n=0,Number1=0,Number2=0,Number3=0;
	while((n=getchar())!='\n')
	{
		if(n >= 97 && n <= 122)
			Number1=Number1+1;
		else if(n >= 65 && n <= 90)
			Number2=Number2+1;
		else if(n >= 49 && n <= 57)
			Number3=Number3+1;
	}
	printf("大写字符数量%d\n",Number1);
	printf("小写字符数量%d\n",Number2);
	printf("数字字符数量%d\n",Number3);
	return 0;
}
