//�����������ǵݹ�������Ԫ��
#include<stdio.h>
typedef BiTree Position;
Position MaxFind(BiTree root){
	if(root){
		while(root->rchild){
			root=root->rchild; 
		} 
	}	
	return root;//�������������һ�ſ�������ôֱ�Ӿͷ����� 
}
