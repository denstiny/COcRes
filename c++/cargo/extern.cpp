#include<iostream>
using namespace std;
extern int cats;
int main(int argc,char *argv[])
{
	 cats = 10;
	 cout << &cats << " | " << cats;
	 return 0;
}
