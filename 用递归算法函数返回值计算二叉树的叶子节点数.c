#include<stdio.h>
int calLeaves(Bitree root){
    if(!root){
        return 0;
    }
    else if(root->lchild==NULL&&root->rchild==NULL)
    {
        return 1;
    }
    else{
        return calLeaves(root->lchild)+calLeaves(root->rchild);
    }
}
