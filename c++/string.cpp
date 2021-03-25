#include <string>
#include "iostream"
int main() {
	std::string st = "hello";
	char buf[100] = " work";
	st += buf;
	std::cout << st << std::endl;
	return 0;
}
