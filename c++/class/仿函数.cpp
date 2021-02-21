#include<iostream>
#include <string>
using namespace std;

class Perjet {
	public:
		void operator() (string test) {
				cout << test << endl;
		}
		int operator() (int &a,int &b)   { 	// 仿函数重载
			a+=b;
			return a;
		}
};

int main(int argc,char *argv[]) {
	Perjet p;
	p("asdf");  // 调用仿函数
	int a = 10,b = 2;
	p(a,b);
	cout << a  << endl;
	//cout p(100,12) << endl;
	return 0;
}
