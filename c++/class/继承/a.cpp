#include<iostream>
using namespace std;

class BaseHead { // 继承节点 配置
	public:
	void Print() {
		cout << "hello world!" << endl;
	}
};

class head:public BaseHead { // 使用 BaseHead 类
};

int main(int argc,char *argv[]) {
	head p;
	p.Print();
	return 0;
}
