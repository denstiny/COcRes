#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int number;
    struct Node *left;
    struct Node *right;
}node;

void *Init_Tree(node *tree,int nuber );//init tree struct 
void *Inster_Node(node *tree);//new node for tree
void *Find_Node(node *root,node *tree);//Find node inster for tree
void *Left_node(node *root,node *tree);//Inster node for Left
void *Right_node(node *root,node *tree);//Inster node for Right
void *Print_tree(node *tree);
int main()

{
    int a;
    node *root = NULL,*head = NULL;
    //root = Init_Tree(root,0);
    for(a = 0;a < 6;a++)
    {
    if(root == NULL)
    {
        root = Inster_Node(root);
        head = root;
    printf("root->number = %d\n",root->number);
    }
    if(root != NULL) 
    {
        root = Inster_Node(root);
        head = Find_Node(head,root);
    }
    }
    Print_tree(head);
    return 0;
}
void *Init_Tree(node * tree,int nuber )
    // Init node for tree

{
    printf("Tree: Init node for tree\n");
    tree         = (node *)malloc(sizeof(node));
    tree->left   = NULL;
    tree->right  = NULL;
    tree->number = nuber;
    
    return tree;
}
void *Inster_Node(node *tree)
    //Inster Node for Tree
{
    int number;
    printf("Tree: Inster node for tree!\n");
    printf("please:input number>");
    scanf("%d",&number);
    tree = Init_Tree(tree,number);
    return tree;
}
void *Find_Node(node *root,node *tree)
    //Find node inster for tree
{
    printf("Find tree->number = %d\n",tree->number);
    printf("Find root->number = %d\n",root->number);
    puts("Find Node");
    if(root->number < tree->number)
    {
        if(root->left == NULL)
        {
            root->left = tree;
        }
        else
        {
            Find_Node(root->left,tree);
        }
    }
    else 
    {
        if(root->right == NULL)
        {
            root->right = tree;
        }
        else
        {
            Find_Node(root->right,tree);
        }
    }
    puts("Find node ok!");
     return root;
    }
void *Right_node(node *root,node *tree)
    //find  inster node for left end  tree
{
    if(root->number > tree->number )
    {
        if(root->right == NULL)
        {
            root->right = tree;
        }

        if(root->right != NULL)
        {
           Right_node(root->right,tree);

        }
    }

    if(root->number < tree->number)
    {
       root->left =  Left_node(root->left,tree);
    }
    return root;

}

void *Left_node(node *root,node *tree)
    //find inster node for right end tree
{
    if(root->number < tree->number)
    {

        if(root->left == NULL)

        {
            root->left = tree;

        }
        else if(root->left != NULL)
        {
             Left_node(root->left,tree);

        }

    }

    if(root->number > tree->number)
      root->right =  Right_node(root->right, tree);
    return root;
}
void *Print_tree(node *tree)
    //printf tree node 
{

    printf("printf tree\n");
    printf("%d\n",tree->number );
    if(tree->left != NULL)
    {
        puts("left ");
        Print_tree(tree->left);
    }
    
    if(tree->right != NULL )
    {
        printf("%p",tree->right);
        puts("right");
        Print_tree(tree->right);

    }

    return 0;
}

