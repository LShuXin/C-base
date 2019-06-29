#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
struct BiTnode{
	ElemType data;
	int lchild,rchild; 
}t[n+1];//在定义结构体的同时定义了一个这样结构结构体数组、数组的每一个空间
//用于存储一个二叉树的节点，为了方便按照完全二叉树的规则从一个节点 寻找他
//的子节点以及左右孩子节点，二叉树结构体数组的大小要比二叉树实际的节点的个数大一，第一个空间不使用 
//二叉树的每一个节点可以通过数组的下标来访问 
