#include<iostream>
using namespace std;
namespace Jack {
	 int a;
	 namespace Jack {
			int a;
			namespace Jack {
				 int a;
			}
	 }
}
int main(int argc,char *argv[])
{
	 using Jack::Jack::Jack::a;
	 a = 10;
	 cout << a << endl;
	 return 0;
}
