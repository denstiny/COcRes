#include <iostream>
using namespace std;
namespace stlib {
	void showtab() {
		cout << "stlib" << endl;
	}
}

namespace stbn {
	void showtab() {
		cout << "stbn" << endl;
	}
}
int main(int argc,char *argv[]) {
	stbn::showtab();
	stlib::showtab();
	using namespace stbn;
	using namespace stlib;
	//ushowtab();
	return 0;
}
