/*********************************************************************************
*     File Name           :     fork.c
*     Created By          :     Aero
*     Github              :     Aero denstiny
*     Creation Date       :     [2020-05-20 12:52]
*     Last Modified       :     [2020-05-21 22:57]
*     Description         :     This is my fast at fork cpp 
**********************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
void *End();
void *End1();
void *End2();
void *End3();
int main()
{
	pid_t id;
	pthread_t th;
	printf("les,go");
	pthread_create(&th,NULL,End,NULL);
	if((id = fork()) < 0)
		perror("fork()");
	else if (id == 0)
	{
	End();
	End1();
	End2();
	End3();
	}
	else
	{
	End();
	End1();
	End2();
	End3();
	}
	return 0;
}
void *End()
{
	sleep(1);
	printf("%d ==>End\n",getpid());
	return NULL;
}
void *End1()
{
	sleep(1);
	printf("End1\n");
	printf("%d ==>End1\n",getpid());

	return NULL;
}
void *End2()
{

	sleep(1);
	printf("End2\n");
	printf("%d ==>End2\n",getpid());
	return NULL;
}
void *End3()
{

	sleep(1);
	printf("End3\n");
	printf("%d ==>End3\n",getuid());
	return NULL;
}
