#include<stdio.h>
///�����������������Ԫ�صĵݹ��㷨
typedef BiTree Position; 
Position MinFind(BiTree root){
	if(!root) { 
		return NULL;//�Ӵ˴�����ֻ�п��ܷ����ڵ�һ�ε��� 
	}else if(root->lchild==NULL){//���û�����ӽڵ��ˣ���ô�ýڵ�һ������С�� 
		return root; 
	}else{//����������ӽڵ㣬��ô�ýڵ�һ��������С 
	    return MinFind(root->lchild); 
	}
} 
