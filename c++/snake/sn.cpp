#include<iostream>
#include<cstdlib>
#include<pthread.h>
#include<termio.h>
#include<ctime>
#include<unistd.h>
#include <string.h>
#include <sys/select.h>
enum Coordinates
{
	X     = 20,
	Y     = 40,
	score = 40,
};

static int Score = 0;
static int map[X][Y] = {0};
static int food[2] = {0};

void *getch(void *ch)
{
	int *sch = (int *)ch;
	*sch = getchar();
	while(getchar() != '\n')
		continue;
	return sch;
}
void RandFood()
{
	srand((unsigned)time(0));
	int x,y;
	while((x = 1+rand() % (X-2) ) != food[0] || (y = 1+rand() % (Y-2) ) != food[1])
	{
		food[0] = x;
		food[1] = y;
	}
	std::cout << food[0] << " | " << food[1] << std::endl;
}

void InitRandCoordinatesSnake(int *coordinates_snake)
{
 //   srand((unsigned)time(0));
 //   int i = 0;
 //   int x = 2+rand() % (X-3);
 //   int y = 2+rand() % (Y-6);
 //   *(coordinates_snake+1) = y;
 //   *(coordinates_snake) = x;
 //   int s = 0;
 //   do{
 //   	*(coordinates_snake+i) = x;
 //   	*(coordinates_snake+i+1) = y+=1;
 //   	i+=2;
 //   }while(i < 2*3);
 //   food[1] = 1+rand() % (X-2);
 //   food[0] = 1+rand() % (Y-2);
}
void PrintMap()
{
		std::cout <<"    " << "::贪::吃::蛇::" << std::endl;
		std::cout <<"    " <<"::分数::" <<Score << "::" <<std::endl;
		std::cout <<"    " <<"::长度::" <<Score+3 << "::" << std::endl;
	for(int i = 0; i < X; i++)
	{
		for(int k = 0; k < Y;k++)
		{
			
			if(i == 0 || i == X-1 || k == 0 || k == Y-1)
				std::cout << ":" << "";
			else if(map[i][k] == 99)
				std::cout << " " << "";
			else if(map[i][k] == 55)
				std::cout << "*" << "";
			else if(map[i][k] == 3)
			 	std::cout << "O" << "";
			else
				std::cout << "▪" << "";
		}
		std::cout << std::endl;
	}

}

int  AddHead(int *coordinates_snake,int x,int y) //移动
{
	if(x == 0 || x == X-1 || y == 0 || y == Y-1)
	{
		std::cout << "::游戏结束::" << std::endl;
		std::cout << "!!请注意不要触碰墙壁!!" << std::endl;
		exit(0);
	}
	else if(map[x][y] > 3 && map[x][y] != 99 && map[x][y] != 55)
	{
		std::cout << "::游戏结束::" << std::endl;
		std::cout << "!!请注意不要咬到自己" << std::endl;
		exit(0);
	}

	int i; for(i = 0;*(coordinates_snake+i) != 0 && *(coordinates_snake+i+1) != 0;i+=2);

	for(i+=2;i != 0;i-=2)
	{
		*(coordinates_snake+i-2) = *(coordinates_snake+i-2) ^ *(coordinates_snake+i);
		*(coordinates_snake+i)   = *(coordinates_snake+i-2) ^ *(coordinates_snake+i);
		*(coordinates_snake+i-2) = *(coordinates_snake+i-2) ^ *(coordinates_snake+i);

		*(coordinates_snake+i-3) = *(coordinates_snake+i-3) ^ *(coordinates_snake+i-1);
		*(coordinates_snake+i-1) = *(coordinates_snake+i-3) ^ *(coordinates_snake+i-1);
		*(coordinates_snake+i-3) = *(coordinates_snake+i-3) ^ *(coordinates_snake+i-1);
	}
	*coordinates_snake = x,*(coordinates_snake+1) = y;
	if(x == food[0] && y == food[1])
	{
		RandFood();
		return 1;
	}
	return 0;
}

void Clear()
{
	system("clear");
}
void DeleteTheLast(int *coordinates_snake)
{
	int i; for(i = 0;*(coordinates_snake+i+2) != 0 && *(coordinates_snake+i+3) != 0;i+=2);
	std::cout << *coordinates_snake << " * " << *(coordinates_snake+1) << std::endl;
	
	map[i][i+1] = 99;
	*( coordinates_snake+i ) = 0,*(coordinates_snake+i+1) = 0;
}

void  SetMap(int *coordinates_snake)
{ 
	int i;
	for(i = 0; i < X; i++)
		for(int k = 0; k < Y;k++)
			map[i][k]={99};
	for(i = 0;*(coordinates_snake+i) != 0 && *(coordinates_snake+i+1) != 0;i+=2)
	{
		if(i/2 +3 < 15)
			map[*(coordinates_snake+i)][*(coordinates_snake+i+1)] = i/2 + 3;
		else
		{
			Clear();
			std::cout << "::恭喜通关::" << std::endl;
			exit(0);
		}

	}
	for(int i = 0;i < 2;i++)
		map[food[0]][food[1]] = 55;

}
void Welcome()
{
	std::cout << "                                                                                " << std::endl;
	std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
	std::cout << "                                                                                " << std::endl;
	std::cout << "                                                                                " << std::endl;
	std::cout << "                                                                                " << std::endl;
	std::cout << "                                                                                " << std::endl;
	std::cout << "  ■■■■■    ■■■        ■■      ■■■      ■■       ■  ■■■■■■ " << std::endl;
	std::cout << "■■■■■■■  ■■■■      ■■    ■■■■■    ■■      ■   ■■■■■■ " << std::endl;
	std::cout << "■■■  ■■■  ■■ ■■     ■■   ■■    ■■   ■■    ■     ■■         " << std::endl;
	std::cout << "■■■          ■■  ■■    ■■  ■■      ■■  ■■  ■       ■■         " << std::endl;
	std::cout << "  ■■■■      ■■   ■■   ■■  ■■      ■■  ■■ ■        ■■■■■■ " << std::endl;
	std::cout << "   ■■■■■   ■■    ■■  ■■  ■■■■■■■  ■■■         ■■■■■■ " << std::endl;
	std::cout << "        ■■■  ■■     ■■ ■■  ■■■■■■■  ■■ ■        ■■         " << std::endl;
	std::cout << "■■■  ■■■  ■■      ■■■■  ■■      ■■  ■■   ■      ■■         " << std::endl;
	std::cout << "■■■■■■■  ■■        ■■■  ■■      ■■  ■■     ■    ■■■■■■ " << std::endl;
	std::cout << "  ■■■■■    ■■          ■■  ■■      ■■  ■■      ■■ ■■■■■■ " << std::endl;
	std::cout << "                                                                                " << std::endl;
	std::cout << "                                                                                " << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
	std::cout << "【C++语言贪吃蛇游戏】bilibili：有点上头的薰衣草 编写!!! \n" << std::endl;
	std::cout << "按任意键开始游戏" << std::endl;
	std::cout << "[上移：w ；下移：s ；左移：a ；右移：d ； 退出：q]\n" << std::endl;								
	while(getchar() != '\n')
		continue;
	system("read -n");
	system("clear");
}

int main(int argc,char *argv[])
{
	Welcome();
	pthread_t th;
	int *coordinates_snake = new int [score*2]; //0:1 x y 
	int *a = new int,al = 's'; *a = 'a';
	InitRandCoordinatesSnake(coordinates_snake); 				//初始化地图
	RandFood();

	SetMap(coordinates_snake); 													//将值带入地图中
	PrintMap();

	while(1)
	{
		int f = 0;
		Clear();
		PrintMap(); 																//打印地图
		pthread_create(&th,NULL,getch,a);
		usleep(500000);
		if(*a == 'a' && al != 'd' || *a == 'd' && al != 'a' ||
				*a == 'w' && al != 's' || *a == 's' && al != 'w' || *a == 'q')
		{
			al = *a;
			switch(*a)
			{
				case 'a': if(AddHead(coordinates_snake,*(coordinates_snake),*(coordinates_snake+1)-1) == 1) f++; break;
				case 'd': if(AddHead(coordinates_snake,*(coordinates_snake),*(coordinates_snake+1)+1) == 1) f++; break;
				case 'w': if(AddHead(coordinates_snake,*(coordinates_snake)-1,*(coordinates_snake+1)) == 1) f++; break;
				case 's': if(AddHead(coordinates_snake,*(coordinates_snake)+1,*(coordinates_snake+1)) == 1) f++; break;
				default:exit(0);
			}
			if(f == 0)
				DeleteTheLast(coordinates_snake); 											//清理尾巴
			else
			{
				Score++;
				RandFood();
			}
			SetMap(coordinates_snake); 													//将值带入地图中
		}
	}
	return 0;
}
