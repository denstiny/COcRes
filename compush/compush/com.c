#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef linux 
#include<unistd.h>
#elif WIN32 || _WIN32
"This can run on linux"
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

NewQueue *TraverseQueue(NewQueue *header) //Traverse queue node ,or queue->ASCLI == str ,return Node or return NULL
{
	while(header->next != NULL)
		header = header->next;
	return header;
}
NewQueue *TraverseQueueStr(NewQueue *header,int str) // Traverse queue ASCLI = str the node
{
	while(header->ASCLI != str && header->next != NULL)
		header = header->next;
	return header;
}

NewQueue *InsertQueue(NewQueue *header,NewQueue *node,int str)
{
	NewQueue * tempNode = NULL; // new temp node ,temp node = node ->last;
	if(header == NULL)
	{
		header = node;
		return header;
	}
	else {
		tempNode = TraverseQueueStr(header,str);
		if(tempNode->ASCLI == str)
		{
			tempNode->size += 1;
			return header;
		}
		else
		{
			tempNode->next = node;
			node->last = tempNode;
			node->size += 1;
			header->sum += 1;
		}
	}
	return header;
}

int main(int argc,char *argv[])
{


	char *string = (char*)malloc(sizeof(char));
	NewQueue * header = NULL;
	int size = 0;
	FILE *file = NULL;
	

	file = fopen(argv[1],"rd");
	while(!feof(file))
	{
		NewQueue * node = malloc(sizeof(NewQueue));
		
		*string = fgetc(file);
		putchar(*string);

		//初始化新节点
		node = InitNode(node,*string);

		if((header = InsertQueue(header,node,*string))== NULL)
			free(node);
		size++;
	}
	printf("node ==> %d\n",header->ASCLI);
	printf("size ==> %d\n",size);
	fclose(file);
	return 0;
}
