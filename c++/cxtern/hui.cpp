#include <cstdio>
#include <iostream>
using namespace std;

#define PRINT(arg...) cout << "hello world " << #arg << endl;

void print(int as) {
	PRINT(我是你的好大哥);
}

template<typename t>
int show(t p) {
	p(10);
	return 0;
}

int main(int argc,char *argv[]) {
	show(print);
	return 0;
}
