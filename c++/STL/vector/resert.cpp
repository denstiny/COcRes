#include <iostream>
#include <vector>
using namespace std;

int main(int argc,char *argv[]) {
	vector<int> v;
	int num,*p = nullptr;
	v.reserve(100000); // 主动分配10000 内存大小 ，省去每次发现内存不足时的自动分配，调高效率
	for (int i = 0; i < 100000; i ++) {
		v.push_back(i);
		if(p != &v[0]) {
			v.begin();
			p = &v[0];
			num++;
		}
	}
	cout << num << endl;
	return 0;
}
