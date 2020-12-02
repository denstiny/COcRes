#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<termio.h>
#include<time.h>

#define X 20
#define Y 40

int map[X][Y] = {0};
enum Map
{
	border = 0, //边框
	food, //食物
	Node  //蛇
};

typedef struct Node
{
	int x;
	int y;
	struct Node *next;
}New_Node;

void Init_Map(int map[X][Y])
{
	for(int x = 0;x < X;x++)
		for(int y = 0;y < Y;y++)
			if(map[x][y] != food)
				map[x][y] = border;
}

void Temp_Main(New_Node *p);

void Read_Food(); //随机生成食物

New_Node *Insert_Node(New_Node *p,int x,int y);

void Print_Map()
{
	system("clear");
	for(int x = 0;x < X;x++)
	{
		for(int y = 0;y < Y;y++)
		{
			if(map[x][y] == border)
				printf("+");
			else if (map[x][y] == food)
				printf("0");
			else printf("●");
		}
		putchar('\n');
	}
}


int getch(void);
int main(int argc,char *argv[])
{
	int c ,cl,len = 0;
	New_Node *p = malloc(sizeof(*p));
	New_Node *head,*temp;
	p->x = 3;
	p->y = 3;
	p->next = NULL;
	head = p;
	Temp_Main(p);
	Read_Food();
	while(1)
	{
		Print_Map();
		c = getch();
		if(c == 'a' && cl != 'd' || c == 'd' && cl != 'a' || c == 'w' && cl != 's' || c == 's' && cl != 'w' || c == 'q')
		{
			
			cl = c;
			New_Node *tem = malloc(sizeof(*tem));
			p = head;
			while(p->next != NULL)
				p = p->next;
			printf("p->x %d p->y %d\n",p->x,p->y);
			switch(c)
			{
				case 97: 
					temp = malloc(sizeof(*temp));
					*temp = *head;
					if(map[head->x][head->y-1] == food)
					{
						
						head->y -= 1;
						tem->x = p->x;
						tem->y = p->y-1;
						tem->next = NULL;
						p->next = tem;
						p = head;
						puts("初始化地图");
						Read_Food();
						puts("重新制作地图");
					}
					else
						head->y -= 1;

					p = head;
					while(temp->next != NULL)
					{
						head->next->x = temp->x;	
						head->next->y = temp->y;
						head = temp->next;
					}
					Init_Map(map);
					Temp_Main(p);
					break;
				case 100:
					if(map[head->x][head->y] == food)
					{
						p->next = tem;
						tem->x = p->x;
						tem->y = p->y+1;
						tem->next = NULL;
						p = head;
						puts("初始化地图");
						Read_Food();
						Init_Map(map);
						puts("重新制作地图");
						Temp_Main(p);
					}else
					{
						head->y += 1;
						Init_Map(map);
						Temp_Main(head);
					}
					break;
				case 's':
					if(map[head->x][head->y] == food)
					{
						p->next = tem;
						tem->x = p->x+1;
						tem->y = p->y;
						tem->next = NULL;
						p = head;
						puts("初始化地图");
						Read_Food();
						Init_Map(map);
						puts("重新制作地图");
						Temp_Main(p);
					}
					else
					{
						head->x += 1;
						Init_Map(map);
						Temp_Main(head);
					}
					break;
				case 'w':

					if(map[head->x][head->y] == food)
					{
						p->next = tem;
						tem->x = p->x-1;
						tem->y = p->y;
						tem->next = NULL;
						p = head;
						puts("初始化地图");
						Read_Food();
						Init_Map(map);
						puts("重新制作地图");
						Temp_Main(p);
					}
					else
					{
						head->x -= 1;
						Init_Map(map);
						Temp_Main(head);
					}
					break;
				case 113: exit(0);
			}
		}
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
void Temp_Main(New_Node *p)
{
	while(p != NULL)	
	{
		map[p->x][p->y] = Node;
		printf("man --> x %d\n man --> y %d\n",p->x,p->y);
		p = p->next;
	}
}
New_Node *Insert_Node(New_Node *p,int x,int y)
{
	New_Node *Temp_Node = malloc(sizeof(*Temp_Node)),*temp = p;
	if(p->next == NULL)
	{
		p->next = Temp_Node;
		Temp_Node->x = x;
		Temp_Node->y = y;
		Temp_Node->next = NULL;
	}
	else 
	{
		while(p->next != NULL)
			p = p->next;
		temp->next = Temp_Node;
		Temp_Node->x = x;
		Temp_Node->y = y;
		Temp_Node->next = NULL;
	}
	printf("Insert:\n x ==> %d\ny ==> %d\n",Temp_Node->x,Temp_Node->y);
	return temp;
}
void Read_Food()
{
	srand((unsigned)time(0));
	map[rand()%X/2][rand()%Y/2] = food;
}
