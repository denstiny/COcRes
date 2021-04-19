#include <iostream>
using namespace std;

int main(int argc,char **argv) {
	int a = 4;

	while(1){
		cout << "if(a < 3)" << endl;
		if(a < 3) {
			cout << a << endl;
			break;
		}
		cout << "if(a = 4)" << endl;
		if( a == 4)  {
			cout << a << endl;
			break;
		}
		cout << "if(a < 4)" << endl;
		if(a < 4) {
			cout << a << endl;
			break;
		}
		cout << "if(a < 2)" << endl;
		if(a < 2) {
			cout << a << endl;
			break;
		}
		break;
	}

	cout << "code end" << endl;
	return 0;
}
