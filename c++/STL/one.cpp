#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

int main(int argc,char *argv[]) {
	using namespace std;
	int a[6] = {27,2,31,45,123,34};
	vector<int,allocator<int>>vi(a,a+6);
	cout << count_if(vi.begin(),vi.end(),not1(bind2nd(less<int>(), 40))) << endl;
	return 0;
}
