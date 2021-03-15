#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

using namespace std;
template<class T>
void Print(int v) {
	cout << v ;
}

template<class T>
void Printf(vector<T> v) {
	for_each(v.begin(), v.end(), Print<T>);
	cout  << " 类型： "<< typeid(T).name() << endl;
}

int main(int argc,char *argv[]) {
	
	vector<int> v1; // 默认构造
	for(int i = 0;i < 10;i++)
		v1.push_back(i);
	Printf(v1);
	
	vector<int> v2(v1.begin(),v1.end()); // 区间构造
	Printf(v2);
	
	vector<int> v3(v2); // 拷贝构造
	Printf(v3);
	return 0;
}
