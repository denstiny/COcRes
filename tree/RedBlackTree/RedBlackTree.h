#ifndef RedBlackTree_h 
#define RedBlackTree_h 
  
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
  
  
typedef int ElementType; 
  
typedef enum { 
 RED, 
 BLACK 
} COLOR; 
  
typedef struct RedBlackNode *RedBlackTree,*Position; 
  
struct RedBlackNode{ 
 ElementType Element; 
 COLOR Color; 
 RedBlackTree Left; 
 RedBlackTree Right; 
}; 
  
static Position NullNode = NULL; 
static Position Header; 
static Position X,P,GP,GGP; 
/* 初始化 */ 
RedBlackTree Initialize(); 
/* 插入 */ 
RedBlackTree Insert(RedBlackTree T,ElementType Item); 
/* 删除 */ 
RedBlackTree Remove(RedBlackTree T,ElementType Item); 
/* 查找 */ 
Position Find(RedBlackTree T,ElementType Item); 
/* 遍历 */ 
void Travel(RedBlackTree T); 
  
  
  
  
#endif /* RedBlackTree_h */
