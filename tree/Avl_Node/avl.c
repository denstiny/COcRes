/*********************************************************************************
*     File Name           :     avl.c
*     Created By          :     Aero
*     Github              :     Aero denstiny
*     Creation Date       :     [2020-08-19 20:58]
*     Last Modified       :     [2020-08-28 22:35]
*     Description         :     This my avl tree  for c language
**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define Endint int 
typedef struct TreeHeadNode TempNode;
struct TreeHeadNode
{
	 Endint Number;
	 TempNode *LNode;
	 TempNode *RNode;
};
TempNode *InitTempNode(TempNode **TreeNode); //初始化节点
Endint main(int argc,char *argv[])
{ TempNode *a = NULL;
	 InitTempNode(&a);
	 return 0;
}
TempNode * InitTempNode(TempNode **TreeNode)
{
	 
	TempNode *node=(TempNode *)malloc(sizeof(TempNode));
	printf("TempNode -> %p\n", node);
	node->LNode = NULL;
	node->RNode = NULL;
	node -> Number = 0;
	if(TreeNode != NULL)
		*TreeNode = node;
	return node;
}
TempNode *Delte_Node(Endint name)
