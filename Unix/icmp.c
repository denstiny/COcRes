#include<stdio.h>
#include<unistdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc,char *argv[])
{
	FILE *fp;
	char buf[] = "Hello world!";
	char str[BUFSIZ] = {0};
	fp  = fopen("./tem.txt","wr");
	fwrite(buf,sizeof(char),0,fp);
	fread(str,sizeof(str),0,fp);
	printf("%s",str);
	fclose(fp);
	return 0;
}

