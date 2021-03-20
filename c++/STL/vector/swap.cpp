#include <iostream>
#include <vector>
using namespace std;

template<class T> 
void Printf(vector<T> &v) {
	for(typename vector<T>::iterator it = v.begin(); it != v.end();it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main(int argc,char *argv[]) {
	
	vector<int> v1;
	for(int i = 10;i > 0;i--) 
		v1.push_back(i);

	vector<int> v2;
	for(int i = 0;i < 10;i++) 
		v2.push_back(i);


	cout << "Swap" << endl;
	Printf(v1);
	Printf(v2);
	v2.swap(v1);
	cout << "run swap" << endl;
	Printf(v1);
	Printf(v2);
	return 0;
}
