#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[]) 
{
	FILE * fp = fopen("file.txt", "r");
	if (fp == NULL) {
		printf("error,No open file");
		return 1;
	}
	//fseek(fp, 0, SEEK_END);
	//int i =ftell(fp);
	//fseek(fp, 0, SEEK_SET);
	//
	//for(int s = 0;s < i ; s++) {
	//	char c = fgetc(fp);
	//	printf("%c",c);
	//	
	//}
	//fseek(fp, 0, SEEK_SET);
	char buf[BUFSIZ];
	memset(buf, 0, BUFSIZ);
	while (*(fgets(buf, BUFSIZ, fp)) != EOF) {
		printf("%s",buf);
	}
	return 0;
}

