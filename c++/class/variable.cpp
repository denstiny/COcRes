#include<iostream>
using namespace std;

class ClassName {
	public:
		int a;
		char b;
		double c;
		long double s;
		void max() {
		}
};


int main(int argc,char *argv[]) {
	ClassName p;
	cout << sizeof(p) << endl;
	
	return 0;
}
