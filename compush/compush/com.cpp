//压缩程序
#ifdef linux
#include<iostream>
#include "config.h"
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<strings.h>
#elif WIN32 || _WIN32
"error: windows no use!"
#endif





int InitNode(NewQueue *Node,int str)
{
	Node->ASCLI = str;
	Node->sum = 0;
	Node->size = 1;
	Node->next = NULL;
	Node->last = NULL;
	return 0;
}

NewQueue * Traverse( NewQueue *head)
	//select Queue last node 

{
	NewQueue * TempNode = head;
	while(TempNode != NULL && TempNode->next != NULL)
		TempNode = TempNode->next;
	return TempNode;
}
NewQueue * TraverseStr(NewQueue *head,int str)
	//select Queue str in node
{
	NewQueue * TempNode = head;
	while(TempNode != NULL && TempNode->next != NULL)
	{
		if(TempNode->ASCLI == str)
			return TempNode;
		TempNode = TempNode->next;
	}
	return NULL;
}

NewQueue* InserQueue(NewQueue *head,NewQueue *TempNode,int str)
{
	NewQueue * Node = NULL;
	if(head->sum == 0)
	{
		head->ASCLI = str;
		head->sum += 1;
		head->next = NULL;
		head->last = NULL;
	}
	else
	{
		if((Node = TraverseStr(head,str)) != NULL)
		{
			Node->size += 1;
			delete TempNode;
		}
		else
		{
			Node = Traverse(head);
			if(Node != NULL)
			{
				head->sum += 1;
				TempNode->ASCLI = str;
				Node->next = TempNode;
				TempNode->last = Node;
			}
			else 
				std::cout << "Insert error:Node no NULL!" << std::endl;
		}
	}
	return head;
}
const NewQueue * TraverseCout(NewQueue *header)
{
	NewQueue *temp = header;
	while(header != NULL && temp != NULL)
	{
		std::cout << "ASCLI: " << (char)temp->ASCLI << "  SUM" << header->sum << std::endl;
		temp = temp->next;
	}
	return NULL;
}

int main(int argc,char *argv[])  // argv[1] --> File argv[2] --> New file
{
	char *da = new char[1024];
	NewQueue *Root = new NewQueue;
	if(argc < 2)
	{
		std::cout << "no open grop file" << std::endl;
		exit(1);
	}
	FILE *file = NULL;
	file = fopen(argv[1],"rb");
	if(file)
	{
		fgets(da,sizeof(da),file);
		int *st = (int *)da;
		while(*(++st)!='\n')
		{
			NewQueue *temp  = new NewQueue;
			//InitNode(temp,str);
			//std::cout <<  st << std::endl;
			InserQueue(Root,temp,*st);
		}
	}
	else
		std::cout << "open file error!" << std::endl;
	TraverseCout(Root);
	fclose(file);
	delete [] da;
	return 0;
}
