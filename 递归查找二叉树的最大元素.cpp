#include<stdio.h>
typedef BiTree Position;
//�����������ݹ�������Ԫ�� 
Position MaxFind(BiTree root){
	if(!root){
		return NULL;
	}else if(!root->rchild){//û�����ӽڵ��˺�����������������Ǹ�Ԫ�� 
		return root; 
	}else{
		return root->rchild;
	}
} 
