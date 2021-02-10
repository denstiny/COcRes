#include<stdio.h>

typedef struct list
{
	 int number;
	 struct list *next,*prot;
}new;

int main(int argc,char *argv[]) 
{
  new root,node1,next;
	root.number = 1;
	root.next = &node1;

	node1.number = 2;
	node1.next = &next;

	next.number = 3;
	next.next = &root;

	root.prot = &next;
	

	new * node = &root;
	
do{
		 printf("%d\n",node->number);
		 node = node->next;
	}while (node != &root);

	return 0;
}
