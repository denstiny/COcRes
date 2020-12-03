#include <iostream>

class Func
{
	public:
		double length;
		double breadth;
		double height;
		Func()
		{
			std::cout << "This is my  The constructor" << std::endl;
			std::cin >> height;
			std::cout << "This is my" << height << std::endl;

		}
		~Func()
		{
			std::cout << "This is my destructor function!" << std::endl;
		}
};
int main()
{
	Func a;
	return 0;
}
