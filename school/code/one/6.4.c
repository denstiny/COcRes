#include<stdio.h>
int main()
{
	int number,s=0,i=0,temp_number,sum=0,n;
	scanf("%d",&number);
	while(s<number)
	{
		s++;
		n = temp_number=s;
		//printf("n=%d\number=%d\ns=%d\n",n,temp_number,s);
		while(n > 0)
		{
			if(n-1!=0)
			{
				n--;
				temp_number*=n;
		//		printf("temp_number===>%d\n",temp_number);
			}
			else n--;
		}
		//printf("%d ->temp_number ==> %d\n",s,temp_number);
		sum += temp_number;
	}
	printf("SUM ==> %d\n",sum);
	return 0;
}
