#include<stdio.h>
int sum=0;
void calLeaves(Bitree root){
//����Ĳ���Ϊһ���������ĸ�ָ��,��ȫ�ֱ�������Ҷ�ӽڵ����Ŀ
  if(root!=NULL){
    if(root->lchild==NULL&&root->rchild==NULL)sum++;
    calLeaves(root->lchild);
    calLeaves(root->rchild);
  }
  return 0;
}
