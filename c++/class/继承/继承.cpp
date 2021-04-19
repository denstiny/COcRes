#include <iostream>
using namespace std;

class Perjet {
	public:
		int a;

		Perjet() {
			a = 10;
		}
};

class PerjetOn:public Perjet{
	public:
	void Print() {
		cout << a << endl;
	}
		
};

int main(int argc,char **argv) {
	PerjetOn p;
	p.Print();
	return 0;
}
