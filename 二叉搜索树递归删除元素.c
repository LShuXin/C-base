#include<stdio.h>
typedef BiTree Position;
Position BiTreeDelete(BiTree root,ElemType data){
    Position temp;
    if(!root){
        printf("δ�ҵ���Ԫ��");
        root=NULL;
    }else if(data<root->data){
        root->lchild=BiTreeDelete(root->lchild,data);
    }else if(data>root->data){
        root->rchild=BiTreeDelete(root->rchild,data);
    }else{
        if(root->lchild&&root->rchild){//���������ڵ������ҽڵ㣬�����ҽڵ����Сֵ�����
            temp=MinFind(root->rchild);//�ҵ��������е���СԪ�ؽڵ�
            root->data=temp->data;//��ɾ���ڵ���������������е���СԪ�������
            root->rchild=BiTreeDelete(root->rchild,temp->data);//����������ɾ����СԪ��
        }else if(!root->lchild){ //���ֻ�����ӽڵ����û�нڵ�
            root=root->rchild;
        }else{//���ֻ�����ӽڵ�
            root=root->lchild;
        }
    }
    return root;
}
