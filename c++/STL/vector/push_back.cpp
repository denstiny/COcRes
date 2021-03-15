#include <iostream>
#include <vector>
#include <string>
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
	for(int i = 1;i <= 10;i++) {
		v1.push_back(i);
	}
	Printf(v1);
	
	// 赋值 operator=
	vector<int>v2;
	v2 = v1;
	Printf(v2);
	
	// assign
	vector<int> v3;
	v3.assign(v1.begin(),v1.end()); // 区间赋值
	Printf(v3);
	
	// n 个 elem 方式赋值
	vector<int>v4;
	v4.assign(10,100);
	Printf(v4);
	return 0;
}
