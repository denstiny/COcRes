#include<iostream>
#include<fstream>
#include<unistd.h>
#include<zlib.h>
#include<cstring>

#define size 1024

int main(int argc,char *argv[])
{


	std::ifstream fd;
	char strStr[size] = {0};
	char buf[size] = {0};
	fd.open(argv[1],std::ios::in | std::ios::binary);
	fd.getline();


	return 0;
}
