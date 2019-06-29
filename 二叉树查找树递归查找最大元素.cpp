//二叉树查找树递归查找最大元素
#include<stdio.h>
typedef BiTree Position;
Position MaxFind(BiTree root){
	if(!root){
		return NULL;//仅有可能在第一次调用时从这里退出 
	}else if(!root->rchild){//如果没有右子节点，则该节点就是最大值
	    return root; 
	}else{
		return MaxFind(root->rchild);
	}
} 
