#include<stdio.h>
#include <error.h>
#include<dirent.h>
int main(int argc,char *argv[]) 
{
	DIR *dp;
	struct dirent *dirp;
	
	if(argc != 2) {
		printf("error is null\n");
		return 1;
	}
	
	if((dp = opendir(argv[1])) == NULL) {
		printf("error is null\n");
		return 1;
	}
	if((dirp = readdir(dp)) == NULL) {
		printf("%s\n",dirp->d_name);
	}
	closedir(dp);
	return 0;
}

