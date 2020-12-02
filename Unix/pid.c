#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int max();   // 进程测试
int Fwrite(int pid,FILE *fp);
int Fread(int pid,FILE *fp);
int main(int argc,char *argv[])
{
	//主进程

	FILE *fp = fopen("./tem.txt","wr");
	pid_t pid = fork();
	if(pid >= 0) Fwrite(0,fp);
	if(pid == 0) Fread(0,fp);
	if(pid < 0)  perror("Fork");
	return 0;
}
int Fread(int pid,FILE *Fp)
{
	printf("主进程\n");
	char str[10] = "\0";
	rewind(Fp);
	if(fread(str,1,strlen(str),Fp) < strlen(str))
	{
		perror("read");
		return 1;
	}
	printf("%s\n",str);
	return 0;
}
int Fwrite(int pid,FILE *Fp)
{
	printf("子进程\n");
	char str[] = "hello world!";
	//FILE * lfp;
	rewind(Fp);
	if((fwrite(str,1,strlen(str),Fp)) < strlen(str))
	{
		perror("Fwrite");
		return 1;
	}
	return 0;
}
