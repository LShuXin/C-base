//��������������������Ҷ�ӽڵ�������㷨
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct BiTnode{
    ElemType data;
    struct BiTnode *lchild,*rchild;
}BiTnode,*BiTree;
int sum=0;//����ͳ��Ҷ�ӽڵ�ĸ���
int siz=sizeof(BiTnode);
BiTree root=NULL;//�������ĸ�ָ��
//���ɶ���������
void creatSortedTree(ElemType x){
   BiTree s,p,q;//�ֱ����ڴ���µĽڵ� Ӧ�ò���Ľڵ��λ���Լ�����λ�õ���һλ��
   s=(BiTree)malloc(siz);
   s->data=x;
   s->rchild=NULL;
   s->lchild=NULL;
   if (root==NULL){//�����������������һ�ſ�������ôֱ�ӽ����ݷ�����ڵ㷵��
      printf("test");
      root=s;
      return ;
   }
   p=root;//����Ӧ�����ҵ��������λ��
   
   while(p)
   {  
       q=p;//q����ָ�����λ�õĸ��ڵ�
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
   //����q�Ѿ�ָ���˲���λ�õĸ��ڵ�
   if(x<q->data){
      q->lchild=s;
   }else{
      q->rchild=s;
   }
   return ;
}
//�����Ǽ��������Ҷ�ӽڵ�������㷨
int calLeaves(BiTree root){
    if(root==NULL){
        return 0;
    }else if(root->lchild==NULL&&root->rchild==NULL){
        return 1;
    }else{
        return calLeaves(root->lchild)+calLeaves(root->rchild);
    }
}
//�����ǲ��Դ��룬����һ�鲻�ظ������ݣ�����һ�Ŷ���������������ͳ��Ҷ�ӽڵ�ĸ���
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
    }while(x!=-9999);//!!!!!!!!!!!!!!����Ҫ�ӷֺ� 
    return 0;
}



