//建立排序二叉树并输出其叶子节点个数的算法
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct BiTnode{
    ElemType data;
    struct BiTnode *lchild,*rchild;
}BiTnode,*BiTree;
int sum=0;//用于统计叶子节点的个数
int siz=sizeof(BiTnode);
BiTree root=NULL;//二叉树的根指针
//生成二叉排序树
void creatSortedTree(ElemType x){
   BiTree s,p,q;//分别用于存放新的节点 应该插入的节点的位置以及插入位置的上一位置
   s=(BiTree)malloc(siz);
   s->data=x;
   s->rchild=NULL;
   s->lchild=NULL;
   if (root==NULL){//如果二叉树本来就是一颗空树，那么直接将数据放入根节点返回
      printf("test");
      root=s;
      return ;
   }
   p=root;//否则应该先找到待插入的位置
   
   while(p)
   {  
       q=p;//q用于指向插入位置的父节点
       if(p->data==x){
          printf("data %d has exited!",x);
          return ;
       }
	 
       if(x<p->data){
       	  p=p->lchild;
	   }else{
	   	  p=p->rchild; 
	   }
   }
   //现在q已经指向了插入位置的父节点
   if(x<q->data){
      q->lchild=s;
   }else{
      q->rchild=s;
   }
   return ;
}
//下面是计算二叉树叶子节点个数的算法
int calLeaves(BiTree root){
    if(root==NULL){
        return 0;
    }else if(root->lchild==NULL&&root->rchild==NULL){
        return 1;
    }else{
        return calLeaves(root->lchild)+calLeaves(root->rchild);
    }
}
//下面是测试代码，输入一组不重复的数据，生成一颗二叉排序树，并且统计叶子节点的个数
int main(){
    int i=0,x;
    do{
        printf("input data%d: ",++i);
        scanf("%d",&x);
        if(x==-9999){
             printf("tree has bin build,it has %d leaves\n",calLeaves(root));
        }else{ 
		   
            creatSortedTree(x);
//            printf("x is %d\n",x);
        }
    }while(x!=-9999);//!!!!!!!!!!!!!!这里要加分号 
    return 0;
}



