#include<iostream>
using namespace std;
string version(const string & s1,const string & s2);
void version(string & s1);
int main(int argc,char *argv[])
{
	string s1 = "asdf",s2 = "as";
	cout << version(s1, s2) << endl;
	version(s1);
	cout << s1 << endl;
	return 0;
}

string version(const string & s1,const string & s2)
{
	string temp;
	temp = s1 + s2;
	return temp;
}

void version(const string & s1)
{
	s1 = "hello wrold";
}
