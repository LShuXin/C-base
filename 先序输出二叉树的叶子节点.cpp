#include<stdio.h>
void PreOrderLeaves(BiTnode root){
	if(root==NULL) return;
	if(!root->lchild&&!root->rchild) printf("%d",root->data);
	PreOrderTraverseLeaves(root->lchild);
	PreOrderTraverseLeaves(root->rchild);
	return ;
} 	
