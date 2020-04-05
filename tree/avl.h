#ifndef AVL_H_
#define AVL_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Size 20
#define STREND char *
int nuber = 0;
typedef  struct Node
{
	char name[Size];
	int size; 
	struct Node *left;
	struct Node *right;
}node;
typedef struct Tree_size //number tree for size 
{
	unsigned int left;
	unsigned int right;
}tr_size;
STREND s_ges(char *str,int n)    // input funicnt
{
	STREND str_end = NULL;
	STREND find = NULL;
	str_end = fgets(str,n,stdin);
	if(str_end)
	{
		find = strchr(str,'\n');
		if(find)
			*find = '\0';
		else
		while(getchar() != '\n')
			continue;
	}
	return str_end;
}
node * Init_Node(node * tree,char *str_end, int n) //init tree for node
{

	tree =(node *) malloc(sizeof(node));
	strcpy(tree->name,str_end); 
	
	tree->size = n ;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}
int Puts_tree(node *tree,int BOOL) //puts tree
{
	if(tree != NULL)
	{
	nuber += 1;
	puts("left");Puts_tree(tree->left,BOOL);
	puts("left");Puts_tree(tree->right,BOOL);
	if(BOOL == 0 )
		printf("==>tree->str :%s\n--->tree->size : %d\n",tree->name,tree->size);
	}
	return nuber;
}
#endif
