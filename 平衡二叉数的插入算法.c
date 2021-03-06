#include<stdio.h>

//平衡二叉树的插入删除查找操作均可以在logN时间完成
//LR型不平衡，问题出现在左子树的右子树中，先右旋，后左旋
//RL型不平衡，问题出现在右子树的左子树中，先左旋，后右旋
//应该注意的是，不平衡类型名与发生问题的位置相对应，但与旋转顺序相反
//其次，两次旋转的时候，第一次旋转，以发现问题的子节点为旋转的根，第二次旋转，以发现问题的节点作为旋转的根
typedef struct AVLNode
{
    //定义平衡二叉数的·节点类型，同普通二叉数不同，
    //多了一个数据域用于存放该节点的不平衡因数
    int data;
    int height;//以该节点为根的树的高
    struct AVLNode *lchild,*rchild;
}*Position,*AVLTree;
//获取树的深度
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
//左单旋算法，问题出现在root的左子树的子节点
AVLTree singleLeftRotation(AVLTree root)
{
    //！！！root是首次发现问题的节点
    //1.指新根
    //2.调小子
    //3.调大子
    //4.调高度
    AVLTree newroot=root->lchild;//根节点的左节点，提到树根的位置，要做新树的根节点
    root->lchild=newroot->rchild;//将出现问题的右子树作为a的左子树
    newroot->rchild=root;//将原来的根节点作为新的根节点的右子树
    //更新平衡因子
    root->height=Max(getHeight(root->lchild),getHeight(root->rchild))+1;
    newroot->height=Max(getHeight(b->lchild),root->height)+1;//上一行已经计算出了根的右子树的高度，直接使用
    return newroot;
}
//右单旋算法，问题出现在右子树的子节点
AVLTree singleRightRotation(AVLTree root)
{
    //root是发现最初发现问题的节点，
    //1.指新
    //2.调小子
    //3.调大子
    //4.调高度
    AVLTree newroot=root->rchild;
    root->rchild=newroot->lchild;
    newroot->lchild=root;
    root->height=Max(getHeight(root->lchild),getHeight(root->rchild))+1;//已经获取了，下面直接用
    newroot->height=Max(root->height,getHeight(root->rchild))+1;
    return newroot;
}


//!!!!!!!!!!!!!!!!!!LR型不平衡，先右旋后左旋
//!!!!!!!!!!!!!!!!!!RL型不平衡，先左旋后右旋
AVLTree doubleLeftRightRoutation(AVLTree root)
{
    //问题发生在左的右子节点中
    //适用于左右不平衡型，先右旋后左旋
    //根据旋转的规则，先旋转下面的，后旋转上面的
    root->lchild=singleRightRotation(root->lchild);
    return singleLeftRotation(root);
}
AVLTree doubleRightLeftRotation(AVLTree root)
{
//问题发生在右子节点左子节点中
//适用于右左不平衡型
//先左旋，后右旋
//旋转的时候也是先旋转下面，后旋转上面
    root->rchild=singleLeftRotation(root->rchild);
    return singleRightRotation(root);
}
//平衡二叉树的插入算法
AVLTree Insert(AVLTree t,ElemType x)
{
    //采用递归插入
    //有四种情况
    //空或者小左大右或者相等
    //最后更新高度
    if(!t)
    {
        AVLnode node=(AVLTree)malloc(sizeof(AVLNode));
        node->data=x;
        node->lchild=node->rchild=NULL;
        node->height=1;/////高度特别容易忽视
        return node;
    }
    else if(data<t->data)
        t->lchild=Insert(t->lchild);
    if(GetHeight(t->lchild)-GetHeight(t->rchild)==2) //需要左旋
    {
        if(x<t->left-data) //左单旋
        {
            t=singleLeftRotation(t);
        }
        else  //左右双旋
        {
            t=doubleLeftRightRoutation(t);
        }

    }
    else if(data>t-data)
    {
        t->rchild=Insert(t->rchild);
        if(x>t->rchild->data) //需要右旋
        {
            if(t->rchild->height-t->lchild->height==2) //需要右旋
            {
                t=singleRightRotation(t);
            }
            else  //需要右左双旋
            {
                t=doubleRightLeftRotation(t);
            }
        }
    }
    else
    {

    }
    //调整高度
    t->height=Max(GetHeight(t->lchild),GetHeight(t->rchild))+1;
}









