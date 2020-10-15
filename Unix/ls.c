#include<dirent.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
	DIR *dir;
	struct dirent *d;
	dir = opendir(argv[1]);
	while((d = readdir(dir)) != NULL)
	printf("%s\t",d->d_name);
	

	return 0;
}
