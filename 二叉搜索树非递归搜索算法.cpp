#include<stdio.h>
//二叉搜索树非递归搜索算法
typedef BiTree Position;
Position Find(BiTree root,ElemType data){
//	if(!root) return NULL;****************没有必要，传过来的是NULL,直接跳过while 返回原来的空值 
	while(root){
		if(root->data==data){
			return root;
		}else if(data<root-<data){
			root=root->lchild; 
		}else{
			root=root->rchild;
		}			
	}
	ruturn root;//如果找不到data，就一直找到最后，也会是NULL 
}

