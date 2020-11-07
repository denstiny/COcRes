/*
 * 班级作业
 * 作者：曹华明
 * */
#include<stdio.h>
#include<stdlib.h>
int one();
int tow();
int three();
int main()
{
	int a;
	printf("1，第一题,\n2，第二题,\n3，第三题,\n4，退出。\n请输入对应编号查询作业:");
		scanf("%d",&a);getchar();
		switch(a)
		{
			case 1:one();break;
			case 2:tow();break;
			case 3:three();break;
			case 4:exit(0);
		}
	return 0;
}
int one()
{
	char *a =(char*) malloc(sizeof(char));
	char b;
	int number = 0,i;
	printf("请输入字符串:");
	while((b=getchar())!='\n')
	{
		*(a+number)=b;
		number++;
	}
	for(i= 0;i<number;i++)
		putchar(*(a+i));
	free(a);
	return 0;
}
int tow()
{
	float a,b;
	printf("请输入两个数用空格隔开:");
	scanf("%f%f",&a,&b);
	printf("%.2f + %.2f=%.f\n",a,b,a+b);
	printf("%.2f - %.2f=%.2f\n",a,b,a-b);
	printf("%.2f x %.2f=%.2f\n",a,b,a*b);
	printf("%.2f %% %.2f=%.2f\n",a,b,(float)(a-(int)(a/b)*b));
	return 0;
}
int three()
{
	int score;
	printf("输入分数：");
	scanf("%d",&score);
	if(score <= 39)
		printf("您的游戏等级是青铜！");
	else if(score >39 && score < 49)
		printf("您的游戏等级是白银");
	else if(score >50 && score <= 59)
		printf("您的游戏等级是");
	else if(score >60 && score <= 69)
		printf("您的游戏等级是黄金");
	else if(score >70 && score <= 79)
		printf("您的游戏等级是铂金");
	else if(score >80 && score <= 89)
		printf("您的游戏等级是钻石");
	else if(score >90 && score <= 100)
		printf("您的游戏等级是星曜");
	return 0;
}
