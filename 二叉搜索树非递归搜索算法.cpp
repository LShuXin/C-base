#include<stdio.h>
//�����������ǵݹ������㷨
typedef BiTree Position;
Position Find(BiTree root,ElemType data){
//	if(!root) return NULL;****************û�б�Ҫ������������NULL,ֱ������while ����ԭ���Ŀ�ֵ 
	while(root){
		if(root->data==data){
			return root;
		}else if(data<root-<data){
			root=root->lchild; 
		}else{
			root=root->rchild;
		}			
	}
	ruturn root;//����Ҳ���data����һֱ�ҵ����Ҳ����NULL 
}

