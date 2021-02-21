#include<iostream>
using namespace std;

class ClassName {
	public:

		ClassName(int age) {
				this->age = age;
		}

		ClassName& increasing(ClassName &p) {  // or 
				this->age += p.age;
				return *this;
		}

		void max() const { // 常函数
			this->age = 100;
		}

		mutable int age;  // 修饰在const特殊情况依然可以修改  常对象只能调用常函数
};



void test() {
	const ClassName p(10);
	cout << p.age << endl;
	p.max();
	cout << p.age << endl;


}

int main(int argc,char *argv[]) {

	ClassName P(1);
	ClassName p2(10);
	ClassName *Ps;

	cout << P.age << endl;
	cout << Ps->age << endl;
	cout << p2.age << endl;

	// 链式编程思想
	P.increasing(p2).increasing(p2).increasing(p2);
	
	cout << P.age << endl;

	P.age = 12;

	cout << P.age << endl;

	test();


	return 0;
}
