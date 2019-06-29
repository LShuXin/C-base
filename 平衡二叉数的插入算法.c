#include<stdio.h>

//ƽ��������Ĳ���ɾ�����Ҳ�����������logNʱ�����
//LR�Ͳ�ƽ�⣬������������������������У���������������
//RL�Ͳ�ƽ�⣬������������������������У���������������
//Ӧ��ע����ǣ���ƽ���������뷢�������λ�����Ӧ��������ת˳���෴
//��Σ�������ת��ʱ�򣬵�һ����ת���Է���������ӽڵ�Ϊ��ת�ĸ����ڶ�����ת���Է�������Ľڵ���Ϊ��ת�ĸ�
typedef struct AVLNode
{
    //����ƽ��������ġ��ڵ����ͣ�ͬ��ͨ��������ͬ��
    //����һ�����������ڴ�Ÿýڵ�Ĳ�ƽ������
    int data;
    int height;//�Ըýڵ�Ϊ�������ĸ�
    struct AVLNode *lchild,*rchild;
}*Position,*AVLTree;
//��ȡ�������
int GetHeight(AVLTree root)
{
    if(!root)
        return 0;
    int lheight,rheight,maxheight;
    lheight=GetHeight(root->lchild);
    rheight=GetHeight(root->rchild);
    maxheight=(lheight>rheight)?lheight:rheight;
    return maxheight;
}
int MAX(int a,int b)
{
    return (a>b)?a:b;
}
//�����㷨�����������root�����������ӽڵ�
AVLTree singleLeftRotation(AVLTree root)
{
    //������root���״η�������Ľڵ�
    //1.ָ�¸�
    //2.��С��
    //3.������
    //4.���߶�
    AVLTree newroot=root->lchild;//���ڵ����ڵ㣬�ᵽ������λ�ã�Ҫ�������ĸ��ڵ�
    root->lchild=newroot->rchild;//�������������������Ϊa��������
    newroot->rchild=root;//��ԭ���ĸ��ڵ���Ϊ�µĸ��ڵ��������
    //����ƽ������
    root->height=Max(getHeight(root->lchild),getHeight(root->rchild))+1;
    newroot->height=Max(getHeight(b->lchild),root->height)+1;//��һ���Ѿ�������˸����������ĸ߶ȣ�ֱ��ʹ��
    return newroot;
}
//�ҵ����㷨��������������������ӽڵ�
AVLTree singleRightRotation(AVLTree root)
{
    //root�Ƿ��������������Ľڵ㣬
    //1.ָ��
    //2.��С��
    //3.������
    //4.���߶�
    AVLTree newroot=root->rchild;
    root->rchild=newroot->lchild;
    newroot->lchild=root;
    root->height=Max(getHeight(root->lchild),getHeight(root->rchild))+1;//�Ѿ���ȡ�ˣ�����ֱ����
    newroot->height=Max(root->height,getHeight(root->rchild))+1;
    return newroot;
}


//!!!!!!!!!!!!!!!!!!LR�Ͳ�ƽ�⣬������������
//!!!!!!!!!!!!!!!!!!RL�Ͳ�ƽ�⣬������������
AVLTree doubleLeftRightRoutation(AVLTree root)
{
    //���ⷢ����������ӽڵ���
    //���������Ҳ�ƽ���ͣ�������������
    //������ת�Ĺ�������ת����ģ�����ת�����
    root->lchild=singleRightRotation(root->lchild);
    return singleLeftRotation(root);
}
AVLTree doubleRightLeftRotation(AVLTree root)
{
//���ⷢ�������ӽڵ����ӽڵ���
//����������ƽ����
//��������������
//��ת��ʱ��Ҳ������ת���棬����ת����
    root->rchild=singleLeftRotation(root->rchild);
    return singleRightRotation(root);
}
//ƽ��������Ĳ����㷨
AVLTree Insert(AVLTree t,ElemType x)
{
    //���õݹ����
    //���������
    //�ջ���С����һ������
    //�����¸߶�
    if(!t)
    {
        AVLnode node=(AVLTree)malloc(sizeof(AVLNode));
        node->data=x;
        node->lchild=node->rchild=NULL;
        node->height=1;/////�߶��ر����׺���
        return node;
    }
    else if(data<t->data)
        t->lchild=Insert(t->lchild);
    if(GetHeight(t->lchild)-GetHeight(t->rchild)==2) //��Ҫ����
    {
        if(x<t->left-data) //����
        {
            t=singleLeftRotation(t);
        }
        else  //����˫��
        {
            t=doubleLeftRightRoutation(t);
        }

    }
    else if(data>t-data)
    {
        t->rchild=Insert(t->rchild);
        if(x>t->rchild->data) //��Ҫ����
        {
            if(t->rchild->height-t->lchild->height==2) //��Ҫ����
            {
                t=singleRightRotation(t);
            }
            else  //��Ҫ����˫��
            {
                t=doubleRightLeftRotation(t);
            }
        }
    }
    else
    {

    }
    //�����߶�
    t->height=Max(GetHeight(t->lchild),GetHeight(t->rchild))+1;
}









