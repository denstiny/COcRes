#include<stdio.h>
#define FLASE 0
#define TRUE 1
#define n(a) a*a*a
int Sxhua_Number(int number);
int main()
{
	int number,sum;
	for(int n = 100;n < 1000;n++)
	{
		if(Sxhua_Number(n) == FLASE)
			printf("%d\n",n);
	}
	return 0;
}
int Sxhua_Number(int number)
{
	int l = number/100;
	int n = (number-(l*100))/10;
	int f = number-(l*100)-(n*10);
	//printf("l ==>%d\nn ==> %d\nf ==> %d\n",l,n,f);
	//printf("n(l) ==> %d\n",n(l));
	if(number == n(l)+n(n)+n(f))
		return FLASE;
	else
		return TRUE;
}

