#include <iostream>
//函数重载

using namespace std;

void func()
{
	printf("helol\n");
	cout << "hello" << endl;
}
void func(int a)
{
	cout << " hello" << endl;
}
int main()
{
	func();
	func(10);
	return 0;
}
