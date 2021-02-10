#include<iostream>
#include "file.h"
using namespace std;
int as(int a,int b);
int main(int argc,char *argv[])
{
	 extern int s;
	 s = 20;
	 cout << s << endl;
	 return 0;
}

int as(int a,int b)
{
	 return a+b;
}

int s = 10;
