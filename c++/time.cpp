#include <iostream>
#include <sys/time.h>
#include <time.h>
using namespace std;

int main(int argc,char **argv) {
	struct timeval tv;
	gettimeofday(&tv, nullptr);
	return 0;
}
