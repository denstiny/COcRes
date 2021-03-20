#include <iostream>
#include <deque>
using namespace std;

template<class T> 
void Printf(deque<T> d) {
	for(typename deque<T>::iterator vd = d.begin(); vd != d.end(); vd++) {
		cout << *vd << " ";
	}
	cout << endl;
}


int main(int argc,char *argv[]) {
	deque<int> d;
	for(int i = 1; i < 5;i ++) {
		d.push_back(i);  // 尾插
	}
	Printf(d);
	
	d.push_front(1000); // 头插
	Printf(d);
	
	
	
	d.pop_back(); 		// 尾删
	Printf(d);
	
	
	
	d.pop_front(); 		// 头删
	Printf(d);
	
	
	
	d.insert(d.begin(),10); // 指定位置插入
	
	deque<int> d2;
	d2.insert(d2.begin(),d.begin(),d.end());
	Printf(d2);
	cout << d2.size() << endl;
	Printf(d2);
	d2.erase(d2.begin());
	Printf(d2);
	cout << "clear" << endl;
	d2.clear();
	Printf(d2);
	return 0;
	
}
