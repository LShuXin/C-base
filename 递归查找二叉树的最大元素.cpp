#include<stdio.h>
typedef BiTree Position;
//二叉搜索树递归查找最大元素 
Position MaxFind(BiTree root){
	if(!root){
		return NULL;
	}else if(!root->rchild){//没有右子节点了毫无疑问这就是最大的那个元素 
		return root; 
	}else{
		return root->rchild;
	}
} 
