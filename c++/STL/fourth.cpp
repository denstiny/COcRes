#include <iostream>
#include <vector> // 容器库
#include <algorithm> // 算法库
using namespace std;

int main(int argc,char *argv[]) {
	vector<int> p {1,2,3,4,5,6,7,8,9,10};
	vector<int>::iterator PAnd = p.begin();
	vector<int>::iterator PEnd = p.end();
	
	
	while (PAnd != PEnd) {
		cout << *(PAnd++) << endl;
	}
	return 0;
}
