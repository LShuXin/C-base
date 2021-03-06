#include<stdio.h>
 typedef struct node{
 	int data;
 	struct BiTnode *lchild,*rchild;//定义二叉树节点类型 
 }BiTnode,*BiTree;//节点。节点指针类型
 BiTree LevelCreatBiTree(){
 	BiTnode *root,*t;
 	int data;
 	SeQueue Q;
 	Q=InitQueue(Q);
 	//读入第一个数据
	scanf("%d",&data) 
	 if(data!=0){//二叉树以eof 为结束的标志，以0为空的标志,如果第一个数据不等于零就开始层序简述
	  root=(BiTree)malloc(sizeof(BiTnode));
	  root->data=data;
	  root->lchild=root->rchild=NULL;
	  InQueue(Q,root);//******************根节点入队，拉下出错！！！！！ 
	 }else{
	 	return NULL;//********************第一次输入的数据仍然可以为0，忘记处理，出错！！！！ 
	 } 
	 //下面开始层序建树
	 while(!IsEmpty(Q)){
	 	t=DeQueue(Q);
	 	//创建左子树
	 	scanf("%d",data);
		if(data!=0){//存在左子节点 
			t->lchild=(BiTree)malloc(sizeof(BiTnode));//分配座子节点的空间 
			t->lchild->data=data;//座子节点赋值 
			t->lchild->lchild=t->lchild->rchild=NULL;//左子节点的数据域都赋为空 
			InQueue(Q,t);//新的节点进队******************拉下，出错 
		}else{//该节点的左子节点不存在
		    t->lchild=NULL; 
		}
	 	//创建右子树
		 scanf("%d",data);
		 if(data!=0){//存在右子节点 
		 	t->rchild=(BiTree)malloc(sizeof(BiTnode));
			t->rchild->data=data;
			t->rchild->lchild=t->rchild->rchild=NULL;
			InQueue(Q,t);//新节点入队*****************落下过，出租 
		 }else{//不存在右子节点 
		 	t->rchild=NULL; 
		 }	
	 }
 	return root;
 } 
 
