#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termio.h>


#define MAX 40
typedef struct Snake
{
	int map_node[20][MAX];
	int a,b;
	int map;
	struct Snake *next;
}New_Snake;

New_Snake *L_Node(New_Snake *Node);   //向左移动
New_Snake *J_Node(New_Snake *Node);   //向下移动
New_Snake *K_Node(New_Snake *Node);   //向上移动
New_Snake *R_Node(New_Snake *Node);   //向右移动

New_Snake *Whil_Snake(New_Snake *Node); //查抄

New_Snake *Rand_map(New_Snake *Node);  //设置食物
 
New_Snake *Rand_Node(New_Snake *Node); //设置随机出生点

New_Snake *Langer_Snake(New_Snake *Node); //清理蛇移动后的尾巴

void Print_Map(New_Snake *Node);  //打印地图

int getch(void);  //构建getch函数

void Next_Node(New_Snake *Node);  //自动开始移动

int main(int argc,char *argv[])
{
	New_Snake *Node = malloc(sizeof(struct Snake));
	
	//设置随机出生点
	Node = Rand_Node(Node);
	
	//打印地图
	Print_Map(Node);
	
	//自动向前移动
	Next_Node(Node);

	return 0;
}
New_Snake *Rand_Node(New_Snake *Node)
{
	//重置随机数
	srand((unsigned)time(0));

	Node->a                          = rand()%18;
	Node->b                          = rand()%MAX-2;
	Node->map_node[Node->a][Node->b] = 3;
	Node->map 						 = 1;
	return Node;
}
void Print_Map(New_Snake *Node)

{
	printf("\
			************\n\
			/** 贪吃蛇 **\n\
			************\n\
			**分数: %d *\n"
									,Node->map);
	Whil_Snake(Node);
						
	if(Node->map == 3)
	{
		system("clear");
		printf("\n\t**********************\n");
		printf("\t******游戏--结束******\n");
		printf("\t**********************\n");
		printf("\t*******得分: %d*******\n",Node->map);
		printf("\t**********************\n");
		if(getchar() == '\n')
		exit(0);
	}
	for(int i = 0;i < 20; i++)
	{
		for(int k = 0;k < MAX; k++)
		{
			if(i == 0 || k == 0 || i == 19 || k == MAX-1)
			{
				printf(":");
				continue;
			}
			if(Node->map_node[i][k] == 0)
			{
				printf("%s","■");
				continue;
			}
			else if (Node->map_node[i][k] == 3) {
				printf("%s","⊙");
			}
			else if(Node->map_node[i][k] == 1)
			{
				printf("★");
			}

		}
		puts("");
	}
}
int getch(void)
{
	struct termios tm,tm_old;
	int fd = 0,ch;
	if(tcgetattr(fd,&tm) < 0)
		return -1;
	tm_old = tm;
	cfmakeraw(&tm);
	if(tcsetattr(fd,TCSANOW,&tm) < 0)
		return -1;
	ch = getchar();
	if(tcsetattr(fd,TCSANOW,&tm_old))
		return -1;
	return ch;
}
//向右移动
New_Snake *L_Node(New_Snake *Node)
{
	New_Snake *p = malloc(sizeof(*p));
	*p = *Node;
	if(Node->map_node[Node->a][Node->b-1] == 1) 
	{
		Node = Rand_map(Node);
		Node->map +=1;
		Whil_Snake(Node)->next = p;
		p->map_node[p->a][p->b] = 3;
	}
	Node->map_node[Node->a][Node->b-=1] = 3;
	Whil_Snake(Node)->map_node[Whil_Snake(Node)->a][Whil_Snake(Node)->b] = 0;
	Node->next = p;
	Node = Langer_Snake(Node);
	return Node;
}
//向左移动
New_Snake *R_Node(New_Snake *Node)
{
		New_Snake *p = malloc(sizeof(*p));
		*p = *Node;
		if(Node->map_node[Node->a][Node->b+1] == 1) 
		{
			Node = Rand_map(Node);
			Node->map +=1;
			Whil_Snake(Node)->next = p;
			p->map_node[p->a][p->b] = 3;
		}
	Whil_Snake(Node)->map_node[Whil_Snake(Node)->a][Whil_Snake(Node)->b] = 0;
	Node->map_node[Node->a][Node->b+=1] = 3;
	Node->next = p;
	Node = Langer_Snake(Node);
	return Node;

}
//向下移动    
New_Snake *J_Node(New_Snake *Node)
{
	//Node->map_node[Node->a][Node->b] = 0;
	New_Snake *p = malloc(sizeof(*p));
	*p = *Node;
	if(Node->map_node[Node->a-1][Node->b] == 1) 
	{
		Node = Rand_map(Node);
		Node->map +=1;
		Whil_Snake(Node)->next = p;
		Node->map_node[p->a][p->b] = 3;
	}
	Whil_Snake(Node)->map_node[Whil_Snake(Node)->a][Whil_Snake(Node)->b] = 0;
	Node->map_node[Node->a-=1][Node->b] = 3;
	Node->next = p;
	Node = Langer_Snake(Node);
	return Node;
}
//向上移动 
New_Snake *K_Node(New_Snake *Node)   
{
	//Node->map_node[Node->a][Node->b] = 0;
	New_Snake *p = malloc(sizeof(*p));
	*p = *Node;
	if(Node->map_node[Node->a+1][Node->b] == 1) 
	{
		Node = Rand_map(Node);
		Node->map +=1;
		Whil_Snake(Node)->next = p;
		p->map_node[p->a][p->b] = 3;
	}
	Whil_Snake(Node)->map_node[Whil_Snake(Node)->a][Whil_Snake(Node)->b] = 0;
	Node->map_node[Node->a+=1][Node->b] = 3;
	Node->next = p;
	Node = Langer_Snake(Node);
	return Node;
}
//随机设置食物
New_Snake *Rand_map(New_Snake *Node)
{

	int a                = rand()%18;
	int b                = rand()%MAX-2;
	Node->map_node[a][b] = 1;
	Node->next           = NULL;
	return Node;
}
New_Snake *Whil_Snake(New_Snake *Node)
	//查找蛇尾巴
{

	int i = 0;
	while(Node->next != NULL)
	{
		Node = Node->next;
		printf("%d :x座标 ==> %d\ty座标 ==>%d\t长度 ==>%d\n",i,Node->a,Node->b,Node->map);
		i++;
	}
	return Node;
}
New_Snake *Langer_Snake(New_Snake *Node)
	
{
	int i = 0;
	while(Node->next != NULL)
	{
		if(i > Node->map)
			Node->map_node[Node->a][Node->b]  = 0;
		i++;
		Node = Node->next;
	}
	return Node;
}
void Next_Node(New_Snake *Node)
	//移动
{
	New_Snake *Temp_Node = Node;
	int a = 'j';
	int num = 0;
	while(1)
	{
		if(num == 0)
			Node =	Rand_map(Node);
		num = 1;
		a = getch();
		switch (a){
			case 'h':Node = L_Node(Node);
					 break;
			case 'j':Node = K_Node(Node);
					 break;
			case 'k':Node = J_Node(Node);
					 break;
			case 'l':Node = R_Node(Node);
					 break;
			case 'q':exit(0);
		  default:continue;
		system("clear");
		}
		Print_Map(Node);
	}

}
