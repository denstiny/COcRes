#include<iostream>
using namespace std;
const double p = 3.14;
class Circle
{
	 public:
			// 公共权限
			int m_r; // 半径
			double M;
			// 获取圆的周长
			double CalculateZC()
			{
				 return 2*p*m_r;
			}
			Circle()
			{
				 cout << "构造函数: " << endl;
				 M = 3*p*2;
			}

};
int main(int argc,char *argv[])
{
	 Circle c;
	 c.m_r = 10;

	 cout << "圆的周长: " << c.CalculateZC() << endl;
	 cout << "圆的周长: " << c.M << endl;
	 return 0;

}
