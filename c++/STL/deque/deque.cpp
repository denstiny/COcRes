#include <iostream>
#include <deque>
using namespace std;

template<class T>
void Printf(const deque<T>& d) {
	for(typename deque<T>::const_iterator de = d.begin();de != d.end();de++) {
		cout << *de << " ";
	}
	cout << endl;
}


int main(int argc,char *argv[]) {
	deque<int> d; // 默认构造
	for(int i : {60,61,62,63,64,65}) {
		d.push_back(i);
	}
	Printf(d);
	// 区间构造
	deque<char>  d1(d.begin(),d.end());
	Printf(d1);
	// 拷贝构造
	deque<int> d2(d);
	Printf(d2);
	
	deque<int> d3(10,1);
	Printf(d3);
	
	deque<int> v3 {};
	v3.swap(d);
	Printf(v3);
	return 0;
}
