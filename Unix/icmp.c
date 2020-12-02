#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	if(argc != 2)
		perror("usage: is directory_name");
	if(( dp = opendir(argv[1] )) == NULL)
		perror("can't open %s");
	while((dirp = readdir(dp)) != NULL)
		puts(dirp->d_name);
	closedir(dp);
	return 0;
}

