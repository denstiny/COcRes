#include <exception>
#include<iostream>
using namespace std;

class Perjet {
	public:
		Perjet(int age) {
			M_age = new int(age);
		}


		int *ReMage() {
			return M_age;
		}

		Perjet& operator=(Perjet &p){
			cout << p.M_age << endl;
			cout << M_age << endl;
				*M_age = *p.M_age;
				cout << "= 重载" << endl;
				return *this;
		}

		~Perjet() {
			if(M_age != nullptr){
				delete M_age;
				M_age = nullptr;
			}
		}
	private:
		int *M_age;
};
int main(int argc,char *argv[]) {

	Perjet p(10);
	cout << *p.ReMage() << endl;

	Perjet b(112);
	cout << *b.ReMage() << endl;


	b = p;

	cout << *p.ReMage() << " | " << p.ReMage() << endl;
	cout << *b.ReMage()  << " | " << b.ReMage() << endl;

	Perjet c(111);

	c = b = c;

	cout << *c.ReMage() << " | "  << c.ReMage()  << " | " << *b.ReMage() << " | "
		<< b.ReMage() << endl;

	cout << &c << " | "<< &b << endl;

	return 0;
}
