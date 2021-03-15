#include <iostream>
using namespace std;

void sypw() {
}

int syw() {
	return 0;
}


template<typename  T>
void ste(T s) {
	cout << typeid(s).name() << endl;
}

int main(int argc,char *argv[]) {
	ste(sypw);
	ste(syw);
	return 0;
}
