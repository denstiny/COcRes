#include <iostream>

class round
{
	public:
		int R_round;
	double cal()
	{
		return 2*3.14*R_round;
	}
};


int main()
{
	round cl;
	cl.R_round = 10;
	std::cout << cl.cal() << std::endl;
	return 0;
}

