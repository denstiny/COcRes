#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void max(char **str);
char *mar(char *str,int a);
int main()
{
	char *str = malloc(sizeof(char));
	max(&str);
	printf("%s",str);
	return 0;
}
void max(char **str)
{
	char s = 'H';
	**str = s;
}
