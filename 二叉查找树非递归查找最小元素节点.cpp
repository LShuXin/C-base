#include<stdio.h>
typedef BiTree Position;
Position MinFind(BiTree root){
	if(root){
		while(root->lchild){//�����ǰ�ڵ����ڵ�Ϊ���ˣ��Ͳ�������ָ�ˣ�root����ָ����СԪ�ؽڵ� 
			root=root->lchild;
		} 
	}
	return root;//�����ʼ����һ�ſ�����Ҳ�����ﷵ�� 	
} 
