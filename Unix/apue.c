#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
void ma();
void Ma();
int main(int argc,char *argv[])
{
	puts("got");
	atexit(ma);
	atexit(Ma);
	return 0;
}
void ma()
{
	printf("helo\n%s",getenv("HOME"));
}

void Ma()
{
	printf("world\n");
}
