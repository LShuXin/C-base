//二叉搜索树非递归查找最大元素
#include<stdio.h>
typedef BiTree Position;
Position MaxFind(BiTree root){
	if(root){
		while(root->rchild){
			root=root->rchild; 
		} 
	}	
	return root;//如果传过来的是一颗空树，那么直接就返回了 
}
