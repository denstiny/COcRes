#include <cstdio>
#include<iostream>
using namespace std;

class Pejeit
{
	public:


		Pejeit() {
			age = 10;
			hei = nullptr;
		}


		Pejeit(int N_age) {
			age = N_age;
		}


		Pejeit(int N_age,int N_hei) {
			age = N_age;
			hei = new int(N_hei);
		}
	~Pejeit() {
		cout << "析构函数调用" << endl;
		if(hei != nullptr){
			delete hei;
		}
	}


	public:
		int age;
		int *hei;
};

int main(int argc,char *argv[])
{
	Pejeit p(11);
	cout << p.age << endl;

	Pejeit p2;
	cout << p2.age << endl;

	Pejeit p3(12,10);
	cout << p3.age << " | " << *p3.hei;
	getchar();
	return 0;
}
