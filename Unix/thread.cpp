#include <iostream>
#include <thread>
using namespace std;

void maix(void) {
	for (int i = 0; i < 10; i++) {
		cout << i << " " << __FUNCTION__ << endl;
	}
}

void max1(void) {
	for (int i = 0; i < 10; i++) {
		cout << i << " " << __FUNCTION__ << endl;
	}
}

int main(int argc,char **argv) {
	thread t(maix);
	thread thread1(max1);

	t.join();
	thread1.join();
	return 0;
}

