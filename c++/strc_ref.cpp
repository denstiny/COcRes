#include<iostream>
#include <utility>
using namespace std;
struct free_throws
{
	string name;
	int made;
	int attempts;
};
string * sw(string & temp1);
free_throws & swap(free_throws & temp1,const free_throws & temp2);
int main(int argc,char *argv[])
{
	free_throws temp1 {"lix",10,19};
	cout << temp1.name << endl;
	free_throws temp2 {"lid",1,2};
	cout << temp2.name << endl;
	swap(temp1,temp2);
	string str = "hello wrold";
	string *s = sw(str);
	cout << temp1.name << endl;
	cout << *s << endl;
	return 0;
}
free_throws & swap(free_throws & temp,const free_throws & temp2)
{
	temp = temp2;
	return temp;
}

string * sw(string & temp1)
{
	string * s = &temp1;
	return s;
}
