#include<iostream>
class complex
{
	public:
		complex(double r = 0,double i = 0)
			:re (r) ,im (i)
		{}
		double real() const {return re;}
		double imag() const {return im;}
	private:
		double re,im;
};
int main()
{
	complex cl(2,4);
	std::cout << cl.real() << std::endl;
	return 0;
}
