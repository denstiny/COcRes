#include <iostream>
using namespace std;

template<class T,class P> 
void TempLatk(T a,P &s) {
	cout << a << endl;
	cout << s << endl;
}

int main(int argc,char *argv[]) {
	TempLatk(10, "1000");
	TempLatk('1', "1");
	return 0;
}
