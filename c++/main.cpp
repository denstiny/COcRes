#include<iostream>
using namespace std;
int max()
{
	cout << "hello wrold" << endl;
	return 10;
}
int main(int argc,char *argv[])
{
	int &a = (int)&max;
	return 0;
}
