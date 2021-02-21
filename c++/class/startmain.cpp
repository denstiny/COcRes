#include <ctime>
#include<iostream>
#include <pthread.h>
#include <type_traits>
using namespace std;

class ClassName {
	public:
		static void max(){
			cout << "hello wrold" << endl;
		}
		ClassName() {
			max();
		}
		~ClassName() {
			max();
			cout << "析构完毕" << endl;
			mar();
		}
	private:
		static void mar() {
			cout << "私有静态函数" << endl;
		}
};


int main(int argc,char *argv[]) {
	ClassName p;
	int a = - 1;
	a *= -1;
	cout << a << endl;
	return 0;
}
