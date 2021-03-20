#include<stdio.h>

void Swap(int *i ,int *b) {
	// Exchange of two variables
	// I think I can test this function directly, and import the two parameters, and run to check the practicality
	*i = *i ^ *b;
	*b = *i ^ *b;
	*i = *i ^ *b;
}


int main(int argc,char *argv[]) 
{
	int i = 10,b = 20;
	Swap(&i, &b);
	printf("i = %d \t b = %d\n",i,b);
	return 0;
}

