#include<iostream>
using namespace std;

double war = 0.3;

void update(double dt);
void local();

int main(int argc,char *argv[])
{
	 cout << "Globl " <<  war << " dd" << endl;

	 update(0.1);
	 cout << "Globl " << war << endl;

	 local();
	 cout << war << endl;
	 return 0;
}

