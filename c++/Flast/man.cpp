#include <iostream>

class Car
{
	public:
		std::string color;
		std::string engine;
		float gas_tank;
		unsigned int Wheel;
	void fill_tank(float liter);
	void runing(void);
	void setColor(std::string color);
	void setEngine(std::string englie);
};

int main(int argc,char *argv[])
{
	Car mycar,car1;
	mycar.setColor("WHITE");
	mycar.setEngine("v8");
	mycar.gas_tank= 85;
	
	return 0;
}
void Car::fill_tank(float liter)
{
	gas_tank +=  liter;	
}

