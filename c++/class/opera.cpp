#include <fstream>
#include <iostream>
#include <ostream>
using namespace std;

class Perjet {

	friend ostream& operator<<(ostream& cou,Perjet &p);
	//friend ostream& operator<<(ostream& cou,Perjet &p) ;

	public:
		int num;
		int snum;
		Perjet(){
			num = 0;
			snum = 0;
			um = 0;
			sum = 0;
		}

// 重载 ++ 运算符
Perjet& operator++() {
	num ++;
	snum ++;
	um ++;
	sum ++;
	return *this;
}

Perjet operator++(int) {

 // Perjet *temp = new Perjet;
 // *temp = *this;
 Perjet temp = *this;
	num++;
	snum++;
	um++;
	sum++;
	return temp;
}

	private:
		int um;
		int sum;
};

ostream& operator<<(ostream& cou,Perjet &p) {
	cou << p.num << " " << p.snum << " " << p.um << " " << p.sum;
	return cou;
}

void test(){
	Perjet p;
	cout << p << endl;
	cout << ++p << endl;
}

void test1() {
	Perjet p;
	cout << p << endl;
	p++;
	cout << p << endl;
	p++;
	cout << p << endl;
}

int main(int argc,char *argv[]) {
	// test();
	test1();
	return 0;
}
