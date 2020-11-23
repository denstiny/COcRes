#include<stdio.h>
int main()
{
	unsigned int n=0,Number_Of[3]={0};
	while((n=getchar())!='\n')
	{
		if(n >= 97 && n <= 122)
			Number_Of[0]+=1;
		else if(n >= 65 && n <= 90)
			Number_Of[1]+=1;
		else if(n >= 49 && n <= 57)
			Number_Of[2]+=1;
	}
	printf("大写字符数量%d\n小写字符数量%d\n数字数量%d\n",Number_Of[1],Number_Of[0],Number_Of[2]);
	return 0;
}
