#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(int argc,char *artv[])
{
	srand((unsigned int)(time(0)));
	for(int a = 1; a < 10; a++)
	{
		int a = rand() % 10;
		printf("随机数==>%d\n",a);
	}
	return 0;
}
