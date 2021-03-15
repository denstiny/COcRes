#include <iostream>
using namespace std;


int main(int argc,char *argv[]) {
	int a = 11,b = 11,c = 12;
	if((a & b) == c) {
		printf( " =  << %d", ((a & b)&c));
	}else 
		printf( " =  << %d",((a & b)&c));
	
	
	return 0;
}
