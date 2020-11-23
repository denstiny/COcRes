#include<stdio.h>
int main()
{
	int ar[]={1,2,4,6,4,1,9,8,7},n = 0, f = sizeof(ar)/sizeof(ar[0]);
	for(int a = 0;a < sizeof(ar)/sizeof(ar[0]);a++)
	{
		for(n = 0;n < f;n ++)
		{
			if(ar[n] > ar[n+1])
			{
				ar[n] = ar[n] ^ ar[n+1];
				ar[n+1] = ar[n] ^ ar[n+1];
				ar[n] = ar[n] ^ ar[n+1];
			}
		}
	}
	n = 0;
	while(n < sizeof(ar)/sizeof(ar[0]))
	{
		printf("%d\n",ar[n]);
		n++;
	}
	return 0;
}

