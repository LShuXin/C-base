#include<stdio.h>
#include<stdlib.h>
typedef int ElemType; 
typedef struct BiTnode{
	ElemType data;
	struct BiTnode *lchild,*rchild; 
}BiTnode,*BiTree;
BiTree root=NULL;
//计算二叉树深度的算法
int getDepth(BiTree root){
	int p=0,d=0;
	if(root==NULL) return p;
	if(root->lchild) d=getDepth(root->lchild);
	if(d>p) p=d;
	if(root->rchild) d=getDepth(root->rchild);
	if(d>p) p=d;
	return p+1; 
} 
//找到 节点为某一确定值的节点，并计算以该点为根节点的树的深度
void getSubDepth(BiTree root,ElemType x){
	if(root->data==x){
		printf("sub tree depth is %d",getDepth(root)); 
		exit(1);
	}else{
		getSubDepth(root->lchild,x);
		getSubDepth(root->rchild,x);
	}	
} 
//生成排序二叉树的算法 
void creatSortTree(ElemType x){
	BiTree p,q,s;//分别指向待插入的节点，待插入节点的父节点以及新生成的节点 
    s=(BiTree)malloc(sizeof(BiTnode));
    s->data=x;
    s->lchild=NULL;
    s->rchild=NULL;
    if(root==NULL) {
    	root=s;
		return ;
	}
	p=root;//root不为空，先找到要插入的位置
	while(p){
		q=p;
		//这里忽略了输入有重复的情况
	    if(p->data==x) {
	    	printf("data:%dhas existed!");
	    	return;
		}
		if(x<p->data){
			p=p->lchild;
		}else{
			p=p->rchild;
		}
	} 
	//现在q已经指向了要插入的节点的父节点
	if(x<q->data){
		q->lchild=s;
	}else{
		q->rchild=s;
	}
    return;
} 
//以下为测试程序
int main(){
	int x,i=0;
	do{ 
	    printf("please input data%d",++i);
		scanf("%d:",&x);
		if(x==-9999){
		 getSubDepth(root,12);	
		 return 0;
		}
	}while(x!=-9999);
	return 0;	
} 
 
