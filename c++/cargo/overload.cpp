#include<iostream>
using namespace std;
void a(int a);
void a(int * a);
int main(int argc,char *argv[])
{
	return 0;
}

void a(int a) { 
	cout << "int" << endl; }
void a(int * a) { 
	cout << "int *" << endl; }
