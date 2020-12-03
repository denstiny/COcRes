#include <iostream>
#include <ctime>
/*
 * 1) 使用二位数组显示面板 ,蛇为1，背景为0
 * 2) 使用时间函数来控制蛇移动速度
 * 3) 贪吃蛇身体跟随蛇移动，只需要记录蛇头位置
 * 4) 用二位数据记录蛇的所有节点
 * */
typedef struct snake
{
	int snakeX;
	int snakeY;
	struct snake *next;
	struct snake *Bread;
}New_Snake;


class CSnake
{
	public:
		int a;
		int b;
};
New_Snake *Init_Map(New_Snake *Node);
New_Snake *DiawSnake();
int main(int argc,char *argv[])
{
	return 0;
}
