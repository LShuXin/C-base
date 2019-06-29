#include<stdio.h>
typedef BiTree Position;
Position MinFind(BiTree root){
	if(root){
		while(root->lchild){//如果当前节点的左节点为空了，就不会往后指了，root保持指向最小元素节点 
			root=root->lchild;
		} 
	}
	return root;//如果初始传入一颗空树，也从这里返回 	
} 
