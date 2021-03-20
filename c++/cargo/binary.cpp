#include <cstdlib>
#include <iostream>

/*
 * 有一种玻璃杯质量确定但未知，需要检测。   
 * 有一栋100层的大楼，该种玻璃杯从某一层楼扔下，刚好会碎。   
 * 现给你两个杯子，问怎样检测出这个杯子的质量，即找到在哪一层楼刚好会碎？(测试最简单的方法)
 * */
#define Floor 100
int main(int argc,char *argv[])
{
	unsigned int floor[Floor] = {0}; //楼层 
	srand((unsigned)time(0));
	int a = rand()%100;
	int sum = 0;
	int num = 0;
	floor[a] = 1; //随机一个楼层是会摔碎
	while(a < 100)
		floor[++a] = 1;
	for(num = Floor/2;num < 100 ;sum ++)
	{
		if(floor[num] == 1)
			num--;
		if(floor[num] == 0)
			num += (Floor -num) /2;
		if(floor[num] == 1 && floor[num-1] == 0)
			break;
	}
	for(int s = 0;s < 100; s++)
		std::cout << s <<"楼   " << floor[s] << std::endl;
	std::cout << num << "楼会摔碎! 评测次数：" << sum <<std::endl;
	return 0;
}
