#include <iostream>
#include <deque>
#include <string>
using namespace std;

template<class T>
void Printf(const deque<T>& v) {
	for(typename deque<T>::const_iterator  d = v.begin(); d != v.end();d++) {
		cout << *d  << " ";
	}
	cout << endl;
}


int main(int argc,char *argv[]) {
	deque<int> d;
	for(int i = 0;i < 10;i++) {
		d.push_back(i);
	}
	Printf(d);
	
	deque<int> d1 = d; 
	Printf(d1);
	
	deque<int> d2;
	d2.assign(d.begin(),d.end());
	Printf(d2);
	deque<int> d3;
	d3.assign(19,1);
	Printf(d3);
	return 0;
}
