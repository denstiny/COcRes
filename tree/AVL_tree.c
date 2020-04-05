#include "avl.h"
node *List_tree(node *root,node *ned);
node * Link_list(node *root,node *strend);
node *SingleRotationForLeft(node *root);
int main(void)
{
	char str[Size];
	int number = 0;
	node *root = NULL,*strend = NULL;
	
	while(s_ges(str,Size) != NULL && str[0] != '\0')
	{
		if(root == NULL)
		{
			strend = Init_Node(root,str,number);
			root = strend;
			number += 1;
		}
		else
		{
			strend = Init_Node(strend,str,number);
			root = Link_list(root,strend);
			number += 1;
		}
	}
	SingleRotationForLeft(root);

	Puts_tree(root,0);
	return 0;
}
node * Link_list(node *root,node *strend)
{
	if(root)
	{
		if(root->name < strend->name)
		{
			if(root->left == NULL)
			{
				root->left = strend;
				strend->size = root->size + 1; 
			}
			else
				Link_list(root->left,strend);
		}
		if(root->name > strend->name)
		{
			if(root->right == NULL)
			{
				root->right = strend;
				strend->size = root->size + 1;
			}
			else 
				Link_list(root->right,strend);
		}
	}
	return root;
}
node *SingleRotationForLeft(node *root)//旋转
{
	
	int a;
	a = Puts_tree(root,1);
	printf("==>> TheTreeHighly :%d\n",a);
	
	return root;
}
