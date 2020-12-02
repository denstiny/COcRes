#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
int main()
{
	int x = 0,y = 0,len = 4,map[900] = {0},c = 'd',cl = 'd',i = 0;
	int s;
	srand((unsigned)time(0));
	while(1)
	{
		map[rand()%900] = -1;
		sleep(1);
		if(cl == 'a' && c != 'd' || cl == 'd' && c != 'a' 
				|| cl == 'w' && c != 's' || c == 's' && c != 'w')
			c = cl;
		if(c == 'a' && --x < 0 || c == 'd' && ++y == 30 ||
			c == 'w' && --y < 0 || c == 's' && ++x == 30)exit(1);
		if(map[y * 30 + x] && map[y * 30 + x] > 0 ? exit(0),1:++len)
			for(i = rand() % 900;map[i] || (map[i] = -1); i = rand() % 900);
		else for(i = 0;i < 900;i++)
			map[i] > 0 ? map[i] -= 1:0;
		for(system("clear"),map[y*30+x] = len,i = 0;i < 900 ;i++)
			puts(map[i] > 0 ? "()" : map[i] ? "00" : " ");
	}
	return 0;
}
