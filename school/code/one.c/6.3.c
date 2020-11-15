#include<stdio.h>
#define TEMP 2
int main()
{
	int temp_sum = 0,number=0,n,Sum=0,temp_sumMK=2;
	printf("Input number:");
	scanf("%d",&n);
	
	while(number < n)
	{
		number++;
		int temp_n = 1;
		while(temp_n<number)
		{
			temp_sumMK = temp_sumMK*10+2;
			temp_n++;
		}
		printf("%d ==> %d\n",number,temp_sumMK);
		Sum += temp_sumMK;
		temp_sumMK=2;
	}
	printf("SUM==>%d\n",Sum);
	return 0;
}
