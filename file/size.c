#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#define BUF 4096
int main()
{
//	char str[BUF];
//	char *strn = (char *)malloc(BUF*sizeof(strn));
//	printf("str = %ld\nstrn = %ld \n",sizeof(str),strlen(strn));

	printf("hello"  ",world from %d\n",getpid());
return 0;}
