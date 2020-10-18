#include<stdio.h>
#include<string.h>
int main()
{
	short int a[11] = {55,56,54,79,115,69,114,116,107,49,50};
	int i;
	for(i = 0; i < 11;i++)
	{
		printf("%c",a[i]);
	}
	printf("\n");
	return 0;
}
