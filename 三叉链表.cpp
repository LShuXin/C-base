#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
//�������� 
struct  BiTnode{
	ElemType data;
	struct BiTnode *lchild,*rchild,*parent;
}*root,*p;//�ڶ���ڵ��������͵�ͬʱ���������������͵�ָ�� 
 
