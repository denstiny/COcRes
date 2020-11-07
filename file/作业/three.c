#include<stdio.h>
int main()
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
