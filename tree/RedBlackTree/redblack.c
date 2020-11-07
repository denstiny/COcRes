#include<stdio.h>
#define Red 1
#define Black 0
/*
 * 1.每个节点要么是黑色，要么是红色
 * 2.根节点一定是黑色
 * 3.每个叶子节点都是黑色
 * 4.每个红色节点的两个子节点都是黑色
 * 5.从任意节点出发到每个叶子节点的路径都包含相同个数的黑色节点。
 * _5.1 如果一个节点存在黑色节点，那么该节点肯定有两个子节点
 * _5.2 黑色完美平衡
 * */
typedef struct RB_tree
{
	int key;
	int color;
	struct RB_tree* left;
	struct RB_tree* right;
	struct RB_tree* p; //父节点
}rb_tree;
//插入节点
rb_tree *Insert_Node(rb_tree *root,rb_tree *Node);
//初始化新节点
rb_tree *Init_Node(rb_tree *Node);
//查找插入节点的位置
rb_tree* Search_Insert_Node(rb_tree *root,rb_tree *Node); 

int main()
{
	return 0;
}
rb_tree *Insert_Node(rb_tree *root,rb_tree *Node)
{
	rb_tree *temp_node,*temp_P_Node,*temp_Pp_Node;
	//插入节点
	if(root->p == NULL)
	{
		root = Node;
		root->color = Black;
		return root;
	}
	temp_node = Search_Insert_Node(root,Node);
	if(temp_node == NULL) // 调整当前节点的父节
	{
		temp_node = Node;
		temp_P_Node = temp_node->p;
		if(temp_P_Node->key < temp_node->key)
			temp_P_Node->left = temp_node;
		if(temp_P_Node->key < temp_node->key)
			temp_P_Node->right = temp_node;
	}
	//调整RedBlack tree
	
	return root;
}
rb_tree *Init_Node(rb_tree *Node)
{
	Node->color = Red;
	Node->key = 0;
	Node->left = NULL;
	Node->right = NULL;
	Node->p = NULL;
	return Node;
}

rb_tree* Search_Insert_Node(rb_tree *root,rb_tree *Node)
{
	if(root != NULL)
	{
		if(root->key < Node->key)
			{
				Node->p = root; 
				Search_Insert_Node(root->left,Node);
			}
		else 
		{
			Node->p = root;
			Search_Insert_Node(root->right,Node);
		}
	}
	else
	{
		root->p = Node->p; //Node在上一次递归中已经保存了root地址
		return root;
	}
	return NULL;
}
rb_tree *Set_Color(rb_tree *Node,int Color)
{
	Node->color = Color;
	return Node;
}
// 左旋转
rb_tree *Left(rb_tree *Node,rb_tree *root)
{
/* 左旋示意图(对节点x进行左旋)：
 *      px                              px
 *     /                               /
 *    x                               y                
 *   /  \      --(左旋)-->           / \                #
 *  lx   y                          x  ry     
 *     /   \                       /  \
 *    ly   ry                     lx  ly  
 *
 *
 */
	rb_tree *Right = Node->right; //将根节点保存在right指针中
	Node->right = Right->left;
	if(Right->left != NULL)
		Right->left->p = Node;
	Right->p = Node->p;
	if(Node->p == NULL) //如果当前节点的父节点为空则设置称根节点
		root = Right;
	else
	{
		if(Node->p->left == Node) //如果父节点的左孩子等于当前节点则把父节点指向当前节点的左节点
			Node->p->left = Right;
		if(Node->p->right == Node)//如果父节点的右孩子等于当前节点则把父节点指向当前节点的右节点
			Node->p->right = Right;
	}
	//将 x 设为 y的左孩子
	Right->left = Node;
	Node->p = Right;
	return Right;
}
// 右旋转
rb_tree *Right(rb_tree *root,rb_tree *Node)
{
	/* 
 * 对红黑树的节点(y)进行右旋转
 *
 * 右旋示意图(对节点y进行左旋)：
 *            py                               py
 *           /                                /
 *          y                                x                  
 *         /  \      --(右旋)-->            /  \
 *        x   ry                           lx   y  
 *       / \                                   / \
 *      lx  rx                                rx  ry
 * 
 */
	rb_tree *Left = Node->left;
	Node->left = Left->right;
	if(Left->right != NULL) //左孩子的右子树不为空时
		Left->right->p  = Node;
	else
	{
		if(Node->p->right == Node)
			Node->p->right = Left;
		if(Node->p->left == Node)
			Node->p->left = Left;
	}
	Left->right = Node;
	Node->p = Left;
	return Left;
}
//修正节点
rb_tree *rb_tree_insert(rb_tree *root,rb_tree *Node)
{
	rb_tree *p,*gp; //p 父母 gp祖父节点 
	rb_tree *uncle,*tmp;
	//若父节点存在,且父节点是红色
	while((p = Node->p) && p->color == Red)
	{
		gp=p->p; 
		if(p == gp->left)
		{
			uncle = gp->right;
			if(uncle && uncle->color == Red)  //  如果叔叔节点是红色
			{
			//将叔叔节点和父母节点染成黑色
				uncle->color = Black;
				p->color = Black;
			gp->color = Red;	
			Node = gp; //将祖父节点设置为新增节点z
			}
			else
				//情况2，Node的叔叔节点是黑色
			{
				if(p->right == Node) //当前节点是右孩子
				{
					root = Right(p,root);
					tmp = p;
					p = Node;
					Node = tmp;
				}
			}
		}
	}
	return 0;
}
