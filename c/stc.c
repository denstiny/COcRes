#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]) 
{
	int temp = 10;
	int * const a  = &temp; // 这个 地址常量
	int const *s = (int *)111;  // 指针值常量
	int tes = 11;
	
	s = &tes;
	*a = 1;
	
	printf("int * const %d\n",*a);
	printf("const int * %d\n",*s);
	return 0;
}

