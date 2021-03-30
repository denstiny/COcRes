#include <stdio.h>
#include <time.h>
#define num 10000000
int main()
{
    time_t starti, endi;
    int i;
	long int start[2];
    int key;
    starti = clock();
	for (i = 0; i < num; i++)
	{
		if (3>0)
			key = 3;
		else if (3 == 2)
			key = 3;
		else if ( 3 > 10 )
			key = 2;
	}
	endi = clock();
	printf("if..else运行%ld次:消耗时间%ld\n",num,endi-starti);
	//printf("key ==> %d\n",key);

	starti = clock();
	for (i = 0; i < num; i++)
	{
		( (3<4) && (key = 3) ) || ( ( 3 == 2 ) && (key = 2 ) ) || ( (3 < 4) && (key = 2)) ;
	}
	endi = clock();
	printf("运算符运行%ld次:消耗时间%ld\n",num,endi-starti);
	//printf("key ==> %d\n",key);


	return 0;
}

