#ifndef CONFIG_H
#define CONFIG_H

#define Clie_IP "127.0.0.1"
#define Clie_prox 7777
#define Serv_IP ""
#define Serv_prox 123
typedef struct Queue
{
	int ASCLI; // char in queue str
	int sum;   // sizeof Queue node number
	int size;  // str sizeof in queue node
	struct Queue * next;
	struct Queue * last;
}NewQueue;
NewQueue * TraverseStr(NewQueue *head,int str);

int InitNode(NewQueue *Node,int str); 
//初始化节点

NewQueue * Traverse( NewQueue *head); 
//查询链表最后一个节点,并返回

NewQueue * TraverseStr(NewQueue *head,int str); 
//返回重复节点


NewQueue* InserQueue(NewQueue *head,NewQueue *TempNode,int str); 
//新建节点 ，插入链表中，返回header节点

const NewQueue * TraverseCout(NewQueue *header);
//遍历 节点

#endif
