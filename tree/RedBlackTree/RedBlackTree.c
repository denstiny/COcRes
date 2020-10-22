#include "RedBlackTree.h" 
  
  
/* 左旋转 */
static Position SingleRotateLeft(Position X); 
/* 右旋转 */
static Position SingleRotateRight(Position X); 
/* 旋转 */
static Position Rotate(Position Parent,Position* Origin ,ElementType Item); 
  
  
/* 左旋转 */
static Position SingleRotateLeft(Position T){ 
 Position TL = T->Left; 
 T->Left = TL->Right; 
 TL->Right = T; 
 return TL; 
} 
/* 右旋转 */
static Position SingleRotateRight(Position T){ 
 Position TR = T->Right; 
 T->Right = TR->Left; 
 TR->Left = T; 
 return TR; 
} 
  
/* 旋转 */
static Position Rotate(Position Parent,Position* Origin ,ElementType Item){ 
 if (Item < Parent->Element){ 
 if (Origin != NULL) 
  *Origin = Parent->Left; 
 return Parent->Left = Item < Parent->Left->Element ? 
 SingleRotateLeft(Parent->Left) : 
 SingleRotateRight(Parent->Left); 
 } 
 else{ 
 if (Origin != NULL) 
  *Origin = Parent->Right; 
 return Parent->Right = Item < Parent->Right->Element ? 
 SingleRotateLeft(Parent->Right) : 
 SingleRotateRight(Parent->Right); 
 } 
  
} 
  
  
/* 初始化 */
RedBlackTree Initialize(){ 
  
 if (NullNode == NULL){ 
 NullNode = malloc(sizeof(struct RedBlackNode)); 
 if (NullNode == NULL) 
  exit(EXIT_FAILURE); 
 NullNode->Element = INT_MAX; 
 NullNode->Color = BLACK; 
 NullNode->Left = NullNode->Right = NullNode; 
   
 } 
  
 Header = malloc(sizeof(struct RedBlackNode)); 
 if (Header == NULL) 
 exit(EXIT_FAILURE); 
  
 /* header的值为无穷小，所以根插入到右边*/
 Header->Element = INT_MIN; 
 Header->Left = Header->Right = NullNode; 
 Header->Color = BLACK; 
  
 return Header; 
  
} 
  
static Position GetSibling(Position Parent,Position X){ 
 if (Parent->Element == INT_MIN) 
 return NULL; 
 if (X == Parent->Left) 
 return Parent->Right; 
 else if (X == Parent->Right) 
 return Parent->Left; 
 else
 return NULL; 
} 
  
void HandleReorientForInsert(ElementType Item){ 
 Position Sibling,Origin; 
  
 /* 当P与X同时为红节点才进行调整 */
 if (X == NullNode || !(P->Color == RED && X->Color == RED)) 
 return ; 
  
  
 Sibling = GetSibling(GP, P); 
  
 if (Sibling == NULL) 
 return ; 
  
  
 /* GP,P,X是成字型，调整为一字型 */
 if ((GP->Element < Item) != (P->Element < Item)){ 
 P = Rotate(GP, &Origin,Item); 
 X = Origin; 
 } 
  
 GP = Rotate(GGP, &Origin,Item); 
 P = Origin; 
  
 /* P的兄弟是黑色的 */
 if (Sibling->Color == BLACK){ 
   
 GP->Color = BLACK; 
 GP->Left->Color = RED; 
 GP->Right->Color = RED; 
   
 } 
 /* P的兄弟是红的 */
 else{ 
   
 GP->Color = RED; 
 GP->Left->Color = BLACK; 
 GP->Right->Color = BLACK; 
 } 
} 
  
RedBlackTree _Insert(RedBlackTree T,ElementType Item){ 
  
 if (T == NullNode){ 
 T = malloc(sizeof(struct RedBlackNode)); 
 T->Element = Item; 
 T->Left = T->Right = NullNode; 
 T->Color = RED; 
 } 
 else if (Item < T->Element) 
 T->Left = _Insert(T->Left, Item); 
 else if (Item > T->Element) 
 T->Right = _Insert(T->Right, Item); 
 /* 重复值不插入 */
  
 X = P,P = GP,GP = GGP, GGP = T; 
  
 HandleReorientForInsert(Item); 
  
 return T; 
} 
  
/* 插入 */
RedBlackTree Insert(RedBlackTree T,ElementType Item){ 
 GGP = GP = P = X = NullNode; 
 T = _Insert(T, Item); 
 T->Right->Color = BLACK; 
 return T; 
} 
  
  
static void _HandleReorientForRemove(ElementType Item){ 
 RedBlackTree Sibling,R; 
 Sibling = GetSibling(P, X); 
  
 if (Sibling == NULL) 
 return ; 
  
 if (Sibling->Left->Color == BLACK && Sibling->Right->Color == BLACK){ 
 P->Color = BLACK; 
 X->Color = RED; 
 Sibling->Color = RED; 
 }else if(Sibling->Left->Color == RED){ 
 R = Sibling->Left; 
   
 P->Color = BLACK; 
 X->Color = RED; 
   
 R = Rotate(P, NULL, R->Element); 
 GP = Rotate(GP, NULL, R->Element); 
   
 }else if (Sibling->Right->Color == RED){ 
 X->Color = RED; 
 P->Color = BLACK; 
 Sibling->Color = RED; 
 Sibling->Right->Color = BLACK; 
   
 GP = Rotate(GP, NULL, Sibling->Element); 
   
 } 
} 
  
static void HandleReorientForRemove(RedBlackTree T, ElementType Item){ 
 RedBlackTree Sibling,Origin,OriginGP; 
 if (X == NullNode) 
 return ; 
  
 /* X有两个黑儿子 */
 if (X->Left->Color == BLACK && X->Right->Color == BLACK){ 
 _HandleReorientForRemove(Item); 
 }else{ 
   
 OriginGP = GP; 
 /* 落到下一层 */
 GP = P; P = X; 
   
 if (Item < X->Element) 
  X = X->Left; 
 else
  X = X->Right; 
   
   
 Sibling = GetSibling(P, X); 
 /* 如果X是黑的，则Sibling是红的，旋转 */
 if (X->Color == BLACK){ 
  GP = Rotate(GP, &Origin, Sibling->Element); 
  P = Origin; 
  GP->Color = BLACK; 
  P->Color = RED; 
  _HandleReorientForRemove(Item); 
   
 } 
   
 /* 恢复X,PX,GP。由于X是当前节点 如果当前节点正是Item，不恢复会影响查找 */
 if (X->Element == Item){ 
  X = P ; P = GP ;GP = OriginGP; 
 } 
   
 } 
} 
  
/* 删除 */
RedBlackTree Remove(RedBlackTree T,ElementType Item){ 
  
 ElementType Origin; 
 Position DeletePtr; 
 Origin = NullNode->Element; 
  
 NullNode->Element = Item; 
  
 GP = P = X = T; 
  
 /* 根染红 */
 T->Right->Color = RED; 
  
 while (X->Element != Item) { 
 GP = P ; P = X; 
 if (Item < X->Element) 
  X = X->Left; 
 else
  X = X->Right; 
   
 HandleReorientForRemove(T, Item); 
 } 
  
  
 NullNode->Element = Origin; 
  
 /* 找到 */
 if (X != NullNode){ 
 DeletePtr = X;  
 if (X->Left != NullNode){ 
  GP = P ; P = X; X = X->Left; 
  HandleReorientForRemove(T, Item); 
  /* 寻找左子树最大值替换 */
  while (X->Right != NullNode) { 
  GP = P ; P = X; 
  X = X->Right; 
  HandleReorientForRemove(T, Item); 
  } 
  if (X == P->Left) 
  P->Left = X->Left; 
  else
  P->Right = X->Left; 
   
 }else if (X->Right != NullNode){ 
  GP = P ; P = X; X = X->Right; 
  HandleReorientForRemove(T, Item); 
  /* 寻找右子树最大值替换 */
  while (X->Left != NullNode) { 
  GP = P ; P = X; 
  X = X->Left; 
  HandleReorientForRemove(T, Item); 
  } 
  if (X == P->Left) 
  P->Left = X->Right; 
  else
  P->Right = X->Right; 
 }else{ 
  /* X是树叶 */
  if (X == P->Left) 
  P->Left = NullNode; 
  else
  P->Right = NullNode; 
 } 
   
 DeletePtr->Element = X->Element; 
 free(X); 
   
 } 
  
 /* 根染黑 */
 T->Right->Color = BLACK; 
  
 return T; 
} 
  
  
  
typedef enum { 
 ROOT, 
 LEFT, 
 RIGHT 
} NodeType; 
  
static char *TypeC; 
static char *ColorC; 
  
void _Travel(RedBlackTree T , NodeType Type){ 
  
 if (T != NullNode){ 
   
 if (Type == ROOT) 
  TypeC = "root"; 
 else if (Type == LEFT) 
  TypeC = "left"; 
 else if (Type == RIGHT) 
  TypeC = "right"; 
   
 if (T->Color == BLACK) 
  ColorC = "black"; 
 else
  ColorC = "red"; 
   
 printf("(%d,%s,%s) ",T->Element,ColorC,TypeC); 
   
 _Travel(T->Left, LEFT); 
 _Travel(T->Right, RIGHT); 
   
 } 
  
} 
  
/* 遍历 */
void Travel(RedBlackTree T){ 
 _Travel(T->Right,ROOT); 
}

int main(int argc,const char *argv[])
{
	RedBlackTree T = Initialize(); 
	T = Insert(T, 10); 
	T = Insert(T, 85); 
	T = Insert(T, 15); 
	T = Insert(T, 70); 
	T = Insert(T, 20); 
	T = Insert(T, 60); 
	T = Insert(T, 30); 
	T = Insert(T, 50); 
	T = Insert(T, 65); 
	T = Insert(T, 80); 
	T = Insert(T, 90); 
	T = Insert(T, 40); 
	T = Insert(T, 5); 
	T = Insert(T, 55); 
	T = Insert(T, 100); 
		
		
	T = Remove(T, 100); 
		
		
	Travel(T); 
	return 0; 
}
