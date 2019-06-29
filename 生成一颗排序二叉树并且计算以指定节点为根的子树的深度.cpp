#include<stdio.h>
#include<stdlib.h>
typedef int ElemType; 
typedef struct BiTnode{
	ElemType data;
	struct BiTnode *lchild,*rchild; 
}BiTnode,*BiTree;
BiTree root=NULL;
//�����������ȵ��㷨
int getDepth(BiTree root){
	int p=0,d=0;
	if(root==NULL) return p;
	if(root->lchild) d=getDepth(root->lchild);
	if(d>p) p=d;
	if(root->rchild) d=getDepth(root->rchild);
	if(d>p) p=d;
	return p+1; 
} 
//�ҵ� �ڵ�Ϊĳһȷ��ֵ�Ľڵ㣬�������Ըõ�Ϊ���ڵ���������
void getSubDepth(BiTree root,ElemType x){
	if(root->data==x){
		printf("sub tree depth is %d",getDepth(root)); 
		exit(1);
	}else{
		getSubDepth(root->lchild,x);
		getSubDepth(root->rchild,x);
	}	
} 
//����������������㷨 
void creatSortTree(ElemType x){
	BiTree p,q,s;//�ֱ�ָ�������Ľڵ㣬������ڵ�ĸ��ڵ��Լ������ɵĽڵ� 
    s=(BiTree)malloc(sizeof(BiTnode));
    s->data=x;
    s->lchild=NULL;
    s->rchild=NULL;
    if(root==NULL) {
    	root=s;
		return ;
	}
	p=root;//root��Ϊ�գ����ҵ�Ҫ�����λ��
	while(p){
		q=p;
		//����������������ظ������
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
	//����q�Ѿ�ָ����Ҫ����Ľڵ�ĸ��ڵ�
	if(x<q->data){
		q->lchild=s;
	}else{
		q->rchild=s;
	}
    return;
} 
//����Ϊ���Գ���
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
 
