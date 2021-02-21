#include<iostream>
using namespace std;

class BasePage {
	public:
		int a;
		BasePage() {
			cout << &b << endl;
		}
	private:
		int b;
	protected:
		int c;
};

class BaseOne:public BasePage {
	public:
		int ba;
		BaseOne() {
			cout << &b << endl;
			ba = 1;
			b = 2;
			cout << ba << " | " << b << endl;
		}
	private:
		int b;  
};

int main(int argc,char *argv[]) {
	BaseOne p;
	BasePage c;
	cout << sizeof(c) << endl;
	cout << sizeof(p) << endl;  // 基类中的所有内容都会继承   大小为20  编译器会自动帮你隐藏 私有内容

	return 0;
}
