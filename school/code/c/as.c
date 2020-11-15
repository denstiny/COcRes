#include<stdio.h>
int main()
{
 	double a=1,b = 1;
	while(b <= 100){
		a*=b;b++;
		printf("%-ld\n",a);
	}

	printf("1乘到一百=>%lf\n",a);
	return 0;
}

