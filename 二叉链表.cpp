#include <stdio.h>
#include<stdlib.h>
typedef char ElemType; 
struct BiTnode{
	struct BiTnode *lchild,*rchild;
	ElemType data;
}*root,*p;//�ڶ����������ṹ�������ͬʱ���������������͵�ָ�� 
