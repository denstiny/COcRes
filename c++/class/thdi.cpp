#include<iostream>
using namespace std;

class ClassName {
	public:
		void SetAge (int ageHeight) {
			age = new int (ageHeight);
		}
		int *M_age() {
			return age;
		}
		~ClassName() {
			delete age;
		}
	private:
		int *age;
};


int main(int argc,char *argv[]) {
	
	ClassName p;
	p.SetAge(100);
	cout << *p.M_age()  << endl;
	return 0;
}
