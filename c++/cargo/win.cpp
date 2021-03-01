#include<iostream>
#include<stdio.h>
#include<cstring>
#ifdef linux
#elif WIN32 || _WIN32
#include<stdio.h>
#endif
	int main()
	{
		std::cout << "hello world" << std::endl;
		return 0;
	}
