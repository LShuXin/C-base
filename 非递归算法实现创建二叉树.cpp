#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
struct BiTnode{
	ElemType data;
	struct BiTnode *lchild,*rchild; 
}; 
typedef struct BiTnode *BiTree;//结构体指针类型*****注意单独定义结构体指针类型前面需要加上typedef，同时也要加上struct 
//使用非递归算法创建二叉树的总体思路：
//1.需要输入二叉树每个节点的编号与该编号处的数据
//2.首先要创建一个二叉树指针数组，数组的每个元素保存相应编号的地址
//对于输入的每一对数据（该节点在二叉树中的编号），都要先创建一个指向这个节点的指针，等该指针所指的区域保存数据完成之后在将这个指针保存到数组中 
BiTree CreatTree(){
	BiTree s[MAXSIZE+1],root,q;//指针类型的数组和变量 
	//指针数组用于保存节点指针 
	int i,j,k,x;
	printf("i,x="); 
	k=scanf("%d,%d",&i,&x);
	printf("%d\n",k);
	printf("%d%d",i,x);
	while(i!=0){
		q=(struct BiTnode*)malloc(sizeof(BiTnode));//分配一个节点空间 
		q->data=x;//数据域赋值 
		q->lchild=q->rchild=NULL;//指针域赋值 
		s[i]=q;//将这块地址保存到指针数组 
		if(i==1){
			root=q;
		}
		j=i/2;//该节点双亲的索引 
		if(i/2){//如果节点的双亲存在 
			if(i%2){//如果当前节点是奇数节点，那么该节点为其双亲节点的右子孙节点 
				s[j]->rchild=q;
			}else{//如果当前节点是奇数节点，那么该节点为其双亲节点的左子孙节点 
				s[j]->lchild=q;
			}		
		} 
		printf("i,x=\n"); 
		scanf("%d,%d",&i,&x);	
	} 
	return root;
} 
int main(){
	struct BiTnode *root1;//新建 一个指向二叉树根节点的指针 
	root1=CreatTree();	
	printf("%d",root1->data);
	printf("%d",root1->lchild->data);
	printf("%d",root1->rchild->data);
}
