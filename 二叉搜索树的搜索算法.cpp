#include<stdio.h>
typedef BiTree Position;

Position Find(BiTree root,ElemType data){
	if(!root){
	    return NULL;	
	}else if(root->data==data) {
	    return root;	
	}else if(data<root->data){/////忘记传参data 
	    return Find(root->lchild,data);
	}else{
		return Find(root->rchild,data);//忘记传参data 
	}	
}
