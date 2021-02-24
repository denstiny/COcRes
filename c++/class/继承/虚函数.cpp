#include<iostream>
using namespace std;

class Perjet {
	public: 
		virtual void max() {
			cout << "Perjet class" << endl;
		}
		Perjet () {
			cout << "This Perjet class" << endl;
		}
};

class BasePerjet: public Perjet {
	public: 
		virtual void max() {
			cout << "BasePerjet class" << endl;
		}
		BasePerjet () {
			cout << "This BasePerjet class" << endl;
		}
};

void BasePeje(Perjet &p) {
	p.max();

}
int main(int argc,char *argv[]) {
	class BasePerjet p;
	class Perjet c;
	BasePeje(p);
	BasePeje(c);
	
	return 0;
}
