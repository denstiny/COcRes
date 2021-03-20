#include <iostream>
#include <deque>
using namespace std;
// deque size The size of the

// 输出函数
template<class T>
vjkkkoid Printf(const deque<T> d) {
	for(typename deque<T>::const_iterator dv = d.begin();dv != d.end();dv++){
		cout << *dv << " ";
	}
	cout << endl;
}

int main(int argc,char *argv[]) {
	deque<int> d;
	// 初始化函数
	for(int i = 0;i < 10;i++)
		d.push_back(i);
	
	Printf(d);
	cout << "d size ==> " << d.size() << endl;
	d.resize(15); // 重新指定 容器的 大小， 多余的内存将默认初始化为0 ，可以实用 d.resize(15,1) 指定多余的内存初始化为1
	cout << "d size ++> " << d.size() << endl;
	Printf(d);
	return 0;
}
