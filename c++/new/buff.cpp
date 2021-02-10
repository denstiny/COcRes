#include <cstdio>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc,char *argv[])
{
	 char buff[100];
	 char *p = new(buff) char[90];

	 for(int b = 0;b < 10;b++)
		 buff[b] = 's';

	 printf("%p\n",buff);

	 printf("%p\n",p);

	 for(int b = 0;b < 100;b++)
			cout << *(p+b) << endl;
	 return 0;
}
