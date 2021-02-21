#include<iostream>
using namespace std;

class Perjet {
	public: // 公共继承
		void PuPrint() {
			cout << "This is my Public !" << endl;
		}
	private: // 私有继承
		void PrPrint() {
			cout << "This is my Private !" << endl;
		}
	protected: // 保护继承
		void PoPrint() {
			cout << "This is my Protected !" << endl;
		}
};


class OnePerjet: public Perjet  { // 共有继承 基类中的保护内容不变
	public:
		OnePerjet() {
			cout << "OnePerjet" << endl;
			PoPrint();
			PuPrint();
			//PrPrint();  基类的私有内容无法访问
		}
};

class TowPerjet: private Perjet { // 私有继承 基类中的保护内容变为私有内容 
	public: 
		TowPerjet() {
			cout << "TowPerjet" << endl;
			PoPrint();
			PuPrint();
			//PrPrint();  基类的私有内容无法访问
		}
};

class TherePerjet: protected Perjet { // 保护继承 基类中共有内容变为保护内容
	public: 
		TherePerjet() {
			cout << "TherePerjet" << endl;
			PoPrint();
			PuPrint();
			//PrPrint();  基类的私有内容无法访问
		}
};


class BasePage: public OnePerjet { // 继承基类 BasePage
	public:
		BasePage() {
			cout << "BasePage" << endl;
			PuPrint();
			PoPrint();
		}
};
class BasePerje :private OnePerjet{
	public:
		BasePerje() {
			cout << "BasePerje" << endl;
			PuPrint(); 
			PoPrint();
		}
};

class BasePuperje: protected OnePerjet {
	public:
		BasePuperje() {
			cout << "BasePuperje" << endl;
			PoPrint();
			PuPrint();
		}
};


int main(int argc,char *argv[]) {
	
	class OnePerjet a;
	a.PuPrint();
	class TowPerjet b;
	class TherePerjet c;

	class BasePage p;
	//p.PuPrint();
	//p.PoPrint();
	
	class BasePuperje pp;
	class BasePerje ppp;
	return 0;
}
