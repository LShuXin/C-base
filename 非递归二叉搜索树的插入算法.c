#include<stdio.h>
typedef BiTree Position;
Position Insert(BiTree root,ElemType data){
    if(!root){//���������ʱ��ֱ�Ӳ�����ڵ㷵��
        root=(BiTree)malloc(sizeof(BiTnode));
        root->data=data;
        root->lchild=root->rchild=NULL;
        return root;
    }
    while(root){
        if()

    }
}
