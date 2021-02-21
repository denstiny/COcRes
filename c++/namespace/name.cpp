#include<iostream>
#include <type_traits>
using namespace std;

namespace Jack {
	 double pail;
	 int pal;
	 namespace ja {
			int pa;
	 }
}

int main(int argc,char *argv[])
{
	 cout << Jack::pail << endl;
	 cout << Jack::ja::pa << endl;
	 return 0;
}
