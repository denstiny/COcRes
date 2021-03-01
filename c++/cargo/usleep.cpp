#include <iostream>
#include <unistd.h>
#include <ctime>
int main()
{
	int a = 1;
	while(a < 100)
	{
		usleep(100000);
		std::cout << a << std::endl;
	}

	return 0;
}
