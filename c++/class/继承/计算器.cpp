#include<iostream>
using namespace std;

template<typename T> // 基类
class Perjet {
	public: 
		virtual T GetNum() {  // 虚函数
			return 0;
		}
};

template<typename T>  // 加法
class BasePerjet: public Perjet<T> {
	public: 
		T a,b;
		T GetNum() {
			return a+b;
		}
};

template<typename T>  // 减法
class sunBase: public Perjet<T> {
	public: 
		T a,b;
		T GetNum() {
			return a-b;
		}
};

template<typename T>
	void Max(Perjet<T> &p) {
		cout << p.GetNum() << endl;
	}


int main(int argc,char *argv[]) {
	BasePerjet<int> p;
	p.a = 10;
	p.b = 29;
	Max(p);
	
	sunBase<float> s;
	s.a = 100;
	s.b = 20;
	Max(s);
	
	return 0;
}
