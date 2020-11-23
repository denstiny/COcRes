#include<stdio.h>
int main()
{
	float number,s=0,i=0,temp_number,sum=0,n;
	scanf("%f",&number);
	while(s<number)
	{
		s++;
		n = temp_number=s;
		while(n > 0)
		{
			if(n-1!=0)
			{
				n--;
				temp_number*=n;
			}
			else n--;
		}
		sum += temp_number;
	}
	printf("SUM ==> %.0f\n",sum);
	return 0;
}
