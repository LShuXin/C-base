#include<stdio.h>
int sum=0;
void calLeaves(Bitree root){
//传入的参数为一个二叉树的根指针,用全局变量保存叶子节点的数目
  if(root!=NULL){
    if(root->lchild==NULL&&root->rchild==NULL)sum++;
    calLeaves(root->lchild);
    calLeaves(root->rchild);
  }
  return 0;
}
