#include<stdio.h>
int  main()
{
	for(int number = 0;number <= 200; number ++)
	{
		if(number%3 == 0)
			continue;
		printf("%d\t\t",number);
	}
	return 0;
}
