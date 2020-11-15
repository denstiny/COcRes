#include<stdio.h>
int main()
{
	int number,i=0,s=0;
	for(number = 75;number <= 100; number ++)
	{
		do{
			printf("char==> %c \t number ==> %d \t",number,number);
			number+=1;
			s++;
		}
		while(s <= i && number <= 100);
		i++;
		s=0;
		puts("");
	}
		
	return 0;
}
