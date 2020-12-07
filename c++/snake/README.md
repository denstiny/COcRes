## c语言答辩作业

<iframe src="https//player.bilibili.com/player.html?aid=843099950&bvid=BV1k54y147hH&cid=263748385&page=1" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

#### 先定义一些初始参数



`思路：定义一个地图，和一个蛇的数组，存储蛇的座标，然后循环打印`



```c++
enum Coordinates
{
	X     = 30, //定义地图X轴大小
	Y     = 50, //定义地图Y轴大小
	score = 40, //定义蛇最长长度
};

static int Score = 0; //分数
static int map[X][Y] = {0}; //初始化地图
static int food[2] = {0};  //食物座标 food[0] X  food[1] Y

```

#### 定义初始化函数

```c++
void InitRandCoordinatesSnake(int *coordinates_snake)
{
	srand((unsigned)time(0)); 		//重置随机数种子
	int i = 0;
	int x = 2+rand() % (X-3); 		//设置蛇头的x轴和y轴座标
	int y = 2+rand() % (Y-6);
	
    *(coordinates_snake+1) = y;
    *(coordinates_snake) = x;
	int s = 0;
	do{ 						//生成两节蛇身
		*(coordinates_snake+i) = x;
		*(coordinates_snake+i+1) = y+=1;
		i+=2;
	}while(i < 2*3);
    food[1] = 1+rand() % (X-2); //生成食物座标
	food[0] = 1+rand() % (Y-2)
}
```

#### 定义main函数

```c
	int *coordinates_snake = new int [score*2]; //0:1 x y   coordinates_snake 存储蛇的座	
	InitRandCoordinatesSnake(coordinates_snake); 		
```



####  将值带入map数组中

```c++
void  SetMap(int *coordinates_snake)  	//coordinates_snake 是存储蛇的座标
{ 
    
    //整个设计思路就是更新coordinates_snake的值 重置map ，将蛇座标带入map中设置特定值作为标识
	int i;
	for(i = 0; i < X; i++)
		for(int k = 0; k < Y;k++)
			map[i][k]={99}; 			//99 为空白，此循环将地图重置为空白
	for(i = 0;*(coordinates_snake+i) != 0 && *(coordinates_snake+i+1) != 0;i+=2)
	{
		if(i/2 +3 < 15) 			//设置分数达到15则成功通关 这里重新设置蛇的座标
			map[*(coordinates_snake+i)][*(coordinates_snake+i+1)] = i/2 + 3;  //将coordinates_snake上蛇的座标带入map中
		else
		{
			Clear();
			std::cout << "::恭喜通关::" << std::endl;
			exit(0);
		}

	}
	for(int i = 0;i < 2;i++)
		map[food[0]][food[1]] = 55; 	//将食物座标带入map并将座标上的值设置成55作为标识

}
```

#### 打印地图

```c
void PrintMap()
{
		std::cout <<"    " << "::贪::吃::蛇::" << std::endl;
		std::cout <<"    " <<"::分数::" <<Score << "::" <<std::endl;
		std::cout <<"    " <<"::长度::" <<Score+3 << "::" << std::endl;
	for(int i = 0; i < X; i++)
	{
		for(int k = 0; k < Y;k++)
		{
			
			if(i == 0 || i == X-1 || k == 0 || k == Y-1) //当碰到这些座标时代表为边框
				std::cout << ":" << ""; 
			else if(map[i][k] == 99) 	 // 99 为空白区域 
				std::cout << " " << "";
			else if(map[i][k] == 55) 	// 55 为食物
				std::cout << "*" << "";
			else if(map[i][k] == 3)		// 当map[x][y] 的值为3代表当前是蛇头
			 	std::cout << "O" << "";
			else
				std::cout << "▪" << ""; // 其他值为身体
		}
		std::cout << std::endl;
	}

}
```

![](/mnt/home/CocRes/c++/snake/Imager/had.png)

![](/mnt/home/CocRes/c++/snake/Imager/snake.png)



### 蛇的移动就是将下一个移动的座标新增一个座标并设置为蛇头，并删除蛇尾

##### 先定义增加蛇头函数

```c
nt  AddHead(int *coordinates_snake,int x,int y) //移动
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
// 通过for循环找到蛇尾的座标
	int i; for(i = 0;*(coordinates_snake+i) != 0 && *(coordinates_snake+i+1) != 0;i+=2);
    

	for(i+=2;i != 0;i-=2)
	{
        //通过或运算 将蛇尾巴的后面一个和蛇尾座标交换，并依次交换到蛇尾巴，则循环结束时，蛇头的的座标为
        //蛇尾座标的下一个空座标
		*(coordinates_snake+i-2) = *(coordinates_snake+i-2) ^ *(coordinates_snake+i);
		*(coordinates_snake+i)   = *(coordinates_snake+i-2) ^ *(coordinates_snake+i);
		*(coordinates_snake+i-2) = *(coordinates_snake+i-2) ^ *(coordinates_snake+i);

		*(coordinates_snake+i-3) = *(coordinates_snake+i-3) ^ *(coordinates_snake+i-1);
		*(coordinates_snake+i-1) = *(coordinates_snake+i-3) ^ *(coordinates_snake+i-1);
		*(coordinates_snake+i-3) = *(coordinates_snake+i-3) ^ *(coordinates_snake+i-1);
	}
	*coordinates_snake = x,*(coordinates_snake+1) = y; //将蛇头的座标设置为新增头座标
	if(x == food[0] && y == food[1])  //如果新增的座标与食物座标相同，代表蛇吃到食物，此时重新分配食物座标
	{
		RandFood(); // 重新分配食物座标函数 大致代码为 food[1] = 1+rand() % (X-2); food[0] = 1+rand() % (Y-2)
		return 1;
	}
	return 0;
}
```

##### 删除蛇尾操作

```c
void DeleteTheLast(int *coordinates_snake)
{
	int i; for(i = 0;*(coordinates_snake+i+2) != 0 && *(coordinates_snake+i+3) != 0;i+=2);
    // 循环查找蛇尾座标
	std::cout << *coordinates_snake << " * " << *(coordinates_snake+1) << std::endl;输出蛇尾座标
	
	map[i][i+1] = 99; //将蛇尾巴座标设置成空
	*( coordinates_snake+i ) = 0,*(coordinates_snake+i+1) = 0; //将存储蛇尾座标指针设置为空
}
```

#### 相关功能函数

##### `Clear()`

```c
void Clear()
{
	system("clear"); 			//做清屏操作
}
```

##### `getch()  `

由于`linux`系统并没有`getch`函数，所以只能自己构建一个

```c
void *getch(void *ch)
{
	int *sch = (int *)ch;
	*sch = getchar();
	while(getchar() != '\n') //过滤输入之后的回车
		continue;
	return sch;
}
```

##### `Welcome`

```c
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
	std::cout << "【C++语言贪吃蛇游戏】迟早编写!!!!\n" << std::endl;
	std::cout << "按任意键开始游戏" << std::endl;
	std::cout << "[上移：w ；下移：s ；左移：a ；右移：d ； 退出：q]\n" << std::endl;								
	while(getchar() != '\n')
		continue;
	system("read -n");
	system("clear");
}
```





### 主函数代码为

```c
int main(int argc,char *argv[])
{
    Welcome();
	pthread_t th;
	int *coordinates_snake = new int [score*2]; //0:1 x y 
	int *a = new int,al = 's'; *a = 'a';
    //初始化地图
	InitRandCoordinatesSnake(coordinates_snake); 				
	RandFood(); 

	SetMap(coordinates_snake); 					//将值带入地图中
	PrintMap();

	while(1)
	{
		int f = 0;
		Clear();
		PrintMap(); 										//打印地图
		pthread_create(&th,NULL,getch,a); 			//新建一个线程更改 *a的值，当前进程继续使用a的值，如果另外一个线程做了更改则，蛇改变方向
		usleep(500000); 		//设置蛇的移动速度为0.5秒一格
		if(*a == 'a' && al != 'd' || *a == 'd' && al != 'a' ||
				*a == 'w' && al != 's' || *a == 's' && al != 'w' || *a == 'q') //做判断禁止蛇往回跑
		{
			al = *a;  //保存蛇上一次方向
			switch(*a)
			{
				case 'a': if(AddHead(coordinates_snake,*(coordinates_snake),*(coordinates_snake+1)-1) == 1) f++; break;			//如果AddHead函数返回1说明吃到食物，则不删除蛇尾巴  否则删除做移动操作
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
```

## 代码演示

[![Watch the video](https://i2.hdslb.com/bfs/archive/0e04ed341fca18c9ba5287cf96bed557cd33100a.jpg@160w_100h_100Q_1c.webp)(](https://www.bilibili.com/video/BV1k54y147hH))]



