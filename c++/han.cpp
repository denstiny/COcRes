#include<iostream>
using namespace std;
double betsy(int);
double pam(int);

void estimate(int lines,double (*pf)(int));
int main(int argc,char *argv[])
{
	int code;
	cout << "HOw many lines of code do you need?";
	cin >> code;
	cout << " Here's Betsy's estimete:\n";
	estimate(code, betsy);
	cout << " Hers's Pam's estimete:\n";
	estimate(code, pam);
	return 0;
}
double betsy(int lns)
{
	return 0.05 * lns;
}
double pam(int lns)
{
	return 0.03 * lns + 0.0004 *lns * lns;
}

void estimate(int lines,double (*pf)(int))
{
	cout << lines << "lines will take";
	cout << (*pf)(lines) << "hour(s)\n";
}
