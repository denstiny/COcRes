#include<iostream>
using namespace std;

class Perjet {
	public:
		int s;
		Perjet() {
			s = 10;
			cout << "This is my Perjet" << endl;
		}
		~Perjet() {
			cout << "This is my Perjet" << endl;
		}
};

class BaseJet :public Perjet {
	public:
		BaseJet() {
			s = 1;
			cout << "This is my BaseJet !" << endl;
		}
		~BaseJet() {
			cout << "This is my BaseJet !" << endl;
		}
};
int main(int argc,char *argv[]) {
	BaseJet p;
	// 继承先构建 基类，然后在构建子类，删除类的时候,先删除子类，然后删除基类
	return 0;
}
