#include<stdio.h>
#include<stdlib.h>
void first(void) {
	printf("This is first function exit\n");
}

void tow(void) {
	printf("This is tow function exit\n");
}

int main()
{
	printf("this is main \n");
	atexit(first);
	atexit(tow);
}
