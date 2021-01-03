#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef linux 
#include<unistd.h>
#elif WIN32 || _WIN32
"傻逼，用你妈的windoiws"
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
	Node->size = 0;
	Node->next = NULL;
	Node->last = NULL;
	return Node;
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

	FILE *file = fopen(argv[1],"rd");
	FILE *NewFile = fopen(argv[2],"wd");
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
	while(header!= NULL)
	{
		printf("node ==> %d\t",header->ASCLI);
		printf("size ==> %d\t",header->size);
		printf("sum ==> %d\n\n",header->sum);
		fputc(header->ASCLI,NewFile);
		header = header->next;
	}
	fclose(file);
	fclose(NewFile);
	return 0;
}
