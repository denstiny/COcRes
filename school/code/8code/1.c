#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void Print(int number[]);
int main()
{
	int number[10] = {0};
	puts("创建随机数初始化素组");
	srand((unsigned int)time(0));
	for(int a = 0;a < 10;a++)
		number[a] = rand()%10;
	printf("排序前  ==>");
	Print(number);
	for(int i = 0,j = 0;i < 10;i++)
	{
		Print(number);
		for(j = i;j < 10;j++)
		{
			if(number[i] > number[j])
			{
				number[i] = number[i] ^ number[j];
				number[j] = number[i] ^ number[j];
				number[i] = number[i] ^ number[j];
			}
		}
	}
	printf("排序结束==>");
	Print(number);
	return 0;
}
void Print(int number[])
{
	for(int i = 0;i < 10;i++)
		printf("%d",number[i]);
	printf("\n");
}
