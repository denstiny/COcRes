#include<iostream>
#include <type_traits>
using namespace std;

class Point
{
	private:
		int m_X;
		int m_Y;
	public:
		void setX(int x){
			m_X = x;
		}
		void setY(int y){
			m_Y = y;
		}
		int getX()
		{
			return m_X;
		}

		int getY()
		{
			return m_Y;
		}
};


class Cirtcle
{
	public:
		void setR(int r){
			m_R = r;
		}
		void setCenter(Point center){
			m_Center = center;
		}
		int getR(){
			return m_R;
		}
		Point getCenter(){
			return m_Center;
		}

	private:
		int m_R; 					// 半径
		Point m_Center; // 园心
};


int main(int argc,char *argv[])
{
	return 0;
}
