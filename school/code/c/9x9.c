#include<stdio.h>
int main()
{
	int line=1,b = 1;
	for(int a = 1;a <= 9; a++)
	{
		for(int b=1;b <= line;b++)
			printf("%dx%d=%d\t",b,a,a*b);
		line++;
		printf("\n");
	}
	return 0;
}
