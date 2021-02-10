#include<iostream>
using namespace std;

extern double war;

void update(double dt)
{
	 extern double war;
	 war += dt;
	 cout << "Update " << war;
	 cout << "degress ";
}
void local()
{
	 int war = 10;
	 cout << "local " << war << "degress";
	 cout << "But global warming  =" << ::war << endl;
	 cout << "degress" << endl;
}

