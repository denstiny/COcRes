/*********************************************************************************
*     File Name           :     fors.c
*     Created By          :     Aero
*     Github              :     Aero denstiny
*     Creation Date       :     [2020-05-20 16:06]
*     Last Modified       :     [2020-05-20 16:24]
*     Description         :     This 测试 
**********************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
void *End1()
{
	printf("%d ==> End()",getpid());
	perror("print");
	return NULL;
}

int main()
{
	pthread_t th;
	pid_t pid;
	pthread_create(&th,NULL,End1,NULL);
	if((pid = fork()) == 0)
	{
		End1();
	}

	return 0;
}
