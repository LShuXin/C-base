#include<stdio.h>
 typedef struct node{
 	int data;
 	struct BiTnode *lchild,*rchild;//����������ڵ����� 
 }BiTnode,*BiTree;//�ڵ㡣�ڵ�ָ������
 BiTree LevelCreatBiTree(){
 	BiTnode *root,*t;
 	int data;
 	SeQueue Q;
 	Q=InitQueue(Q);
 	//�����һ������
	scanf("%d",&data) 
	 if(data!=0){//��������eof Ϊ�����ı�־����0Ϊ�յı�־,�����һ�����ݲ�������Ϳ�ʼ�������
	  root=(BiTree)malloc(sizeof(BiTnode));
	  root->data=data;
	  root->lchild=root->rchild=NULL;
	  InQueue(Q,root);//******************���ڵ���ӣ����³����������� 
	 }else{
	 	return NULL;//********************��һ�������������Ȼ����Ϊ0�����Ǵ������������� 
	 } 
	 //���濪ʼ������
	 while(!IsEmpty(Q)){
	 	t=DeQueue(Q);
	 	//����������
	 	scanf("%d",data);
		if(data!=0){//�������ӽڵ� 
			t->lchild=(BiTree)malloc(sizeof(BiTnode));//�������ӽڵ�Ŀռ� 
			t->lchild->data=data;//���ӽڵ㸳ֵ 
			t->lchild->lchild=t->lchild->rchild=NULL;//���ӽڵ�������򶼸�Ϊ�� 
			InQueue(Q,t);//�µĽڵ����******************���£����� 
		}else{//�ýڵ�����ӽڵ㲻����
		    t->lchild=NULL; 
		}
	 	//����������
		 scanf("%d",data);
		 if(data!=0){//�������ӽڵ� 
		 	t->rchild=(BiTree)malloc(sizeof(BiTnode));
			t->rchild->data=data;
			t->rchild->lchild=t->rchild->rchild=NULL;
			InQueue(Q,t);//�½ڵ����*****************���¹������� 
		 }else{//���������ӽڵ� 
		 	t->rchild=NULL; 
		 }	
	 }
 	return root;
 } 
 
