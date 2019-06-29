#include<stdio.h>
typedef BiTree Position;
Position Insert(BiTree root,ElemType data){
    if(!root){//输入空树的时候直接插入根节点返回
        root=(BiTree)malloc(sizeof(BiTnode));
        root->data=data;
        root->lchild=root->rchild=NULL;
        return root;
    }
    while(root){
        if()

    }
}
