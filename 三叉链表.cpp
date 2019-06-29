#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
//三叉链表 
struct  BiTnode{
	ElemType data;
	struct BiTnode *lchild,*rchild,*parent;
}*root,*p;//在定义节点数据类型的同时定义了两个该类型的指针 
 
