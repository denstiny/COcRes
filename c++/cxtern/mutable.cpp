#include<iostream>
using namespace std;
struct data
{
	 char name[20];
	 mutable int ese;
};
int main(int argc,char *argv[])
{
	 const data temp {"asdfasdf",10};
	 temp.ese = 1;
	 cout << temp.name << temp.ese << endl;
	 return 0;
}
