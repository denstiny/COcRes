#include<iostream>
using namespace std;

class Perjet {

	friend class Persn;  // 设置友元类  使Persn 可以访问当前类的隐私内容

	public:

		Perjet() {
			number = 10;
		}

	private:
		int number;

};

class Persn {
	public:

		void Pesn(Perjet &p) {
			cout << p.number << endl;
		}
};


void tert() {
	Persn p;
	Perjet h;
	p.Pesn(h);
}

int main(int argc,char *argv[]) {
	tert();
	
	return 0;
}
