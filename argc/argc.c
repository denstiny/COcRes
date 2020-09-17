#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
	ent *a[2];
	a[0] =(int *) malloc(sizeof(int));

	*a[0] = 2;
	printf("%d\n",*a[0]);
	return 0;
}
