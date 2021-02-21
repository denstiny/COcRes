#include<iostream>
using namespace std;
namespace Jack {
int line;
}

namespace Jock {
int line;
}
int main(int argc,char *argv[])
{
	 Jack::line = 10;
	 Jock::line = 20;

	 int pal = 30;
	 cout << Jack::line << endl
			<< Jock::line << endl
			<< pal << endl;
	 return 0;
}
