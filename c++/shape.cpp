#include<iostream>
#include <cstring>
using namespace std;
int harpo(char s[100],int size = sizeof(s));
int main(int argc,char *argv[])
{
	harpo("asdf");
	return 0;
}
int harpo(int s ,int size )
{
	cout << "n ==>" << s << endl << "s ==>" << size << endl;
	return 0;
}
