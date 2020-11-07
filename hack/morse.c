#include<stdio.h>
#include<string.h>
int main()
{
	int i = 0;
	char str[] = "11 111 010 000 0 1010 111 100 0 00 000 000 111 00 10 1 0 010 0 0  00 1 00 10 110";
	while(i<strlen(str))
	{
		if(str[i] == '1')
			str[i] = '-';
		else if(str[i] == '0')
			str[i] = '.';
		i++;
	}
	printf("%s\n",str);
	return 0;
}
