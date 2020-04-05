#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Size 30
char *S_gets(char *str,int n);
int  main(void)
{
	char input[Size];
	//char *input = malloc(char);
	S_gets(input,Size);
	puts(input);
}
char *S_gets(char *str,int n)
{
	char *str_end=NULL,*find = NULL;
	str_end = fgets(str,n,stdin);
	if(str_end)
	{
	//puts("fgets");
	find = strchr(str,'\n');
	if(find)
		*find = '\0';
	else 
		while(getchar() != '\n')
			continue;
	}
		
	return str_end; 
}


