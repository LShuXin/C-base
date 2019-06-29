#include <stdio.h>
#include<stdlib.h>
typedef char ElemType; 
struct BiTnode{
	struct BiTnode *lchild,*rchild;
	ElemType data;
}*root,*p;//在定义二叉链表结构体变量的同时定义了两个该类型的指针 
