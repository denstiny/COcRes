#include<iostream>
using namespace std;
namespace jill {
double fech;
}
using namespace jill;
int main(int argc,char *argv[])
{
	 cout << &jill::fech << endl;
	 fech = 10;
	 cout << &fech << endl;
	 return 0;
}
