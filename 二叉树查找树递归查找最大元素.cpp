//�������������ݹ�������Ԫ��
#include<stdio.h>
typedef BiTree Position;
Position MaxFind(BiTree root){
	if(!root){
		return NULL;//���п����ڵ�һ�ε���ʱ�������˳� 
	}else if(!root->rchild){//���û�����ӽڵ㣬��ýڵ�������ֵ
	    return root; 
	}else{
		return MaxFind(root->rchild);
	}
} 
