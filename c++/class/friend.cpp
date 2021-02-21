#include<iostream>
using namespace std;

class clxear {

	friend void max(clxear &p);  // 友元 是全局函数 max可以访问 私有变量和函数

	public:
	int a;
	private:
	int b;

};

void max(clxear &p)
{
	p.a = 100;
	p.b =10;
	
	cout << p.a << " | " << p.b << endl;
}


int main(int argc,char *argv[]) {
	clxear p;
	max(p);
	
	return 0;
}
