#include<iostream>
using namespace std;
void dribble(const char *bits);
void dribble(char *bits);


int main(int argc,char *argv[])
{
	char *str;
	const char *st;
	dribble(str);
	dribble(st);
	return 0;
}

void dribble(const char *bits) { cout << "cont char" << endl; }
void dribble(char *bits) { cout << "char" << endl; }
