#include<stdio.h>
#include<errno.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#define STREND char *
STREND s_ges(char *str,int n);
int main(int argc,char *argv[])
{
	DIR *dp;
	FILE *p;
	char *filename = malloc(BUFSIZ*(sizeof(char)));
	char *str = malloc(BUFSIZ*(sizeof(char)));
	struct dirent * dirp;
	if(argc != 2)
		perror("argc");
	if((dp = opendir(argv[1])) ==NULL)
		perror("opendir");
	str = s_ges(str,30);
	while((dirp = readdir(dp)) != NULL)
	{
		printf("%s\n",dirp->d_name);
		if((p = fopen(dirp->d_name,"r")) != NULL)
		{
			fgets(filename,BUFSIZ,p);
			puts(filename);
			filename = strpbrk(filename,str);
			puts(filename);
		}
	}

	return 0;
}

STREND s_ges(char *str,int n)
{
	STREND str_end = NULL;
	STREND find = NULL;
	str_end = fgets(str,n,stdin);
	if(str_end)
	{
		find = strchr(str,'\n');
		if(find)
			*find = '\0';
		else
		while(getchar() != '\n')
			continue;
	} 
	return str_end;
}
