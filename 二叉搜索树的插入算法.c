#include<stdio.h>
typedef BiTree Position;
Position Insert(BiTree root,ElemType data){
    if(!root){//����������һ�ſ�����ֱ�ӽ�Ԫ�ز��뵽���ڵ��ϣ������ظ��ڵ�
        root=(BiTree)malloc(sizeof(BiTnode));
        root->data=data;
        root->lchild=root->rchild=NULL;
        return root;/////!!!!!!!!!!!!!!!!!!!**********���Ƿ���**************
    }else if(data<root->data){
        return Insert(root->lchild,data);//Ӧ�ò嵽������
    }else if(data>root->data){
        return Insert(root->rchild,data);//Ӧ�ò嵽������
    }else{//�ҵ��˾�ֱ�ӷ��ظ�λ��
        return root;
    }
}
