#include<stdio.h>
int main()
{
	int Str_Number,Big_Char = 0,Show_char = 0,Other = 0;
	for(;(Str_Number = getchar()) != '\n';)
	{
		if(Str_Number >= 65 && Str_Number <= 90)
			Big_Char++;
		else if(Str_Number >= 97 && Str_Number <= 122)
			Show_char++;
		else 
			Other++;
	}
	printf("Bid letter:%d \t Show letter:%d\t Other:%d\n",Big_Char,Show_char,Other);
	return 0;
}
