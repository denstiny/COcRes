#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <csetjmp>
using namespace std;
static jmp_buf env;
void max(void) {
	if(setjmp(env) == 1 )
		printf(":Call %s\n",__FUNCTION__);
	longjmp(env, 1);
}

void mab(void) {
	printf(":Call %s\n",__FUNCTION__);
		max();
}

int main(int argc,char **argv) {
	if(!setjmp(env))
		mab();	
	return 0;
}
