#include<stdio.h>
int main(){
	//�������Ĳ������
	void LevalTraverse(BiTree root){
		if(root==NULL) return;
		SeQueue Q;
		Q=InitQueue(Q);
		InQueue(Q,root);
		while(!IsEmpty(Q)){
			BiTnode node;
			node=Dequeue(Q);
			printf("%d",node->data);
			LevelTraverse(node->lchild);
			LevelTraverse(node->rchild);
		}	
	} 
	return;	
} 
