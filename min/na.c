#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *fpr[BUFSIZ];fpr[0] = malloc(sizeof(char));
	char *fps[BUFSIZ];
	scanf("%s",fpr[0]);
	fps[0] = fpr[0];
	puts(fps[0]);
	return 0;

}
