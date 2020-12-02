#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termio.h>


int getch(void);  //构建getch函数

int main()
{
	int x = 0,y = 0,map[20][40] = {0},len = 0,i = 0,k = 0,c = 0,cl = 0;
	srand((unsigned)time(0));
	while(1)
	{
		map[rand()%20][rand()%40] = -1;
		c = getch();
		if(c == 'a' && cl != 'd' || c == 's'  && cl != 'w' || c == 'd' && c != 'a'
				|| c == 'w' && c != 's') c = cl;
		if(c == 'a' && --x < 0 || c == 's' && --y < 0 || c == 'w' && ++x < 30 || c == 'd' && --y < 30)
		
		 for(i = rand()%30 ; map[i][k] || ( map[i][k-1] = -1 );i = rand()%30);
		

	}
	return 0;
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
