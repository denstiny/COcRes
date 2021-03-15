#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



void Print(int v) {
	cout << v << endl;
}
// vector 容器
int main(int argc,char *argv[]) {
	
	vector<int> v; // 创建一个容器，数组
	// 向容器中插入数据
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);
	
	
	vector<int>::iterator itbegin = v.begin(); // 起始迭代器，指向容器中的第一元素
	vector<int>::iterator itend = v.end(); // 结束迭代器，指向容器中的最后一个迭代器
	
	//for(;itbegin != v.end() ;itbegin++)
	//	cout << *itbegin << endl;
	for_each(v.begin(), v.end(), Print);
	return 0;
}


