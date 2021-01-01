#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef linux 
#include<unistd.h>
#elif WIN32 || _WIN32
"error"
#endif

typedef struct Queue
{
	int ASCLI; // char in queue str
	int sum;   // sizeof Queue node number
	int size;  // str sizeof in queue node
	struct Queue * next;
	struct Queue * last;
}NewQueue;


NewQueue* InitNode(NewQueue *Node,int str)
{
	Node->ASCLI = str;
	Node->sum = 0;
	Node->size = 1;
	Node->next = NULL;
	Node->last = NULL;
	return Node;
}

NewQueue *TraverseQueue(NewQueue *header,int* str)
	//Traverse queue node ,or queue->ASCLI == str ,return Node or return NULL
{
	return NULL;
}

NewQueue *InsertQueue(NewQueue *header,NewQueue *node,int str)
{
	return NULL;
}

int main(int argc,char *argv[])
{
	char *string = (char*)malloc(sizeof(char));
	NewQueue *header = malloc(sizeof(NewQueue));
	int size = 0;
	FILE *file = NULL;
	file = fopen(argv[1],"rd");
	while(!feof(file))
	{
		NewQueue * node = malloc(sizeof(NewQueue));
		InitNode(node,*string);
		*string = fgetc(file);
		putchar(*string);
		InsertQueue(header,node,*string);
		size++;
	}
	printf("size ==> %d\n",size);
	fclose(file);
	return 0;
}
