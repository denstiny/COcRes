#include <iostream>
using namespace std;
template <typename T>
inline T const& Max(T const & a,T const &b)
{
	return a < b ? b:a;
}
class name
{
	//public 的声明在类的内外可见，并可按需要进行设置，调用和操纵。一般原则是不把类的数据做成public，因为数据保持私有才符合面向对象的理论之一：只有类本身才能改变自己的数据，外部函数只能调用类的成员函数，这就保证类类的数据只会以合乎规则的方式被更新
	public:
		std::string color;
		std::string engine;
		float gas_tank;
		unsigned int Wheel;
};
int main(int argc,char *argv[])

{
	int i = 39;
	int j = 20;
	cout << "max(i,j):" << Max(i,j) << endl;

	double f1 = 13.5; 
	double f2 = 20.7; 
	cout << "Max(f1, f2): " << Max(f1, f2) << endl; 

	string s1 = "Hello"; 
	string s2 = "World"; 
	cout << "Max(s1, s2): " << Max(s1, s2) << endl; 

	return 0;
}

