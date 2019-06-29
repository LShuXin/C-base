#include<stdio.h>
typedef char TElemType;
typedef struct Node{
	TElemType data;
	struct Node *rchild,lchild;
}BiTreeNode,*BiTree;
typedef struct{
	BiTree T;
	int tag;
}StackElemType;
