#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<pthread.h>
#include<termio.h>
void* getch(void *ch)
{
	struct termios tm,tm_old;
	int fd = 0,*sch;
	if(tcgetattr(fd,&tm) < 0)
		return NULL;
	tm_old = tm;
	cfmakeraw(&tm);
	if(tcsetattr(fd,TCSANOW,&tm) < 0)
		return NULL;
	sch =(int *)ch;
	*sch = getchar();
	if(tcsetattr(fd,TCSANOW,&tm_old))
		return NULL;
	return sch;
}

void* Getch(void *ch)
{
	int *sch = (int *)ch;
	*sch = getchar();
	while(getchar() != '\n')
		continue;
	return ch;
}

int main()
{
	pthread_t th;

	int *a = new int ,b = 0;
	*a = 0;
	while(b < 10)
	{
		sleep(1);
		b++;
	//	pthread_create(&th,NULL,getch,a);
		std::cout << "User >> " << *a << std::endl;
	}
	return 0;
}
