#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
int main(int argc,char **argv) {
	char *a = alloca(100);
	memset(a,99,100);
	puts(a);
	return 0;
}
