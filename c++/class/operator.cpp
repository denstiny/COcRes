#include<iostream>
using namespace std;

class Perjet {

	friend ostream& operator<<(ostream &cout,Perjet &p) ;

	public: 

		int ba;
		int bb;

		Perjet() {
			ba = 0;
			bb = 0;
			sa = 0;
			sb = 0;
		}
		Perjet(int number,int number2) {
			ba = number;
			bb = number2;
		}

	Perjet operator+(Perjet &p) {  // 成员重载
		Perjet temp;
		temp.ba = this->ba + p.ba;
		temp.bb = this->bb + p.bb;
		return temp;
	}
	private:
		int sa;
		int sb;
};

ostream& operator<<(ostream &cout,Perjet &p)
{
	cout << p.ba << " | " << p.bb << endl << p.sa << " | " << p.sb;
	return cout;
}

Perjet operator-(Perjet &p,Perjet &b)  { // 全局函数重载
	Perjet temp;
	temp.ba = p.ba + b.ba;
	temp.bb = p.bb + b.bb;
	return temp;
}

Perjet operator+(Perjet &p,int num){
	Perjet temp;
	temp.ba = p.ba + num;
	temp.bb = p.bb + num;
	return temp;
}



int main(int argc,char *argv[]) {
	
	Perjet a(1,2);
	Perjet b(3,4);
	Perjet c = a + b;

	cout << (a+b).ba << " | " << (a+b).bb << endl;
	cout << (a-b).ba << " | " << (a-b).bb << endl;
	cout << (a+10).ba << " | " << (a+2).bb << endl;

	cout << c << " hello wrold" << endl; 
	return 0;
}
