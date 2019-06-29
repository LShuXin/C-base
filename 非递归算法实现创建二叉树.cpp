#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
struct BiTnode{
	ElemType data;
	struct BiTnode *lchild,*rchild; 
}; 
typedef struct BiTnode *BiTree;//�ṹ��ָ������*****ע�ⵥ������ṹ��ָ������ǰ����Ҫ����typedef��ͬʱҲҪ����struct 
//ʹ�÷ǵݹ��㷨����������������˼·��
//1.��Ҫ���������ÿ���ڵ�ı����ñ�Ŵ�������
//2.����Ҫ����һ��������ָ�����飬�����ÿ��Ԫ�ر�����Ӧ��ŵĵ�ַ
//���������ÿһ�����ݣ��ýڵ��ڶ������еı�ţ�����Ҫ�ȴ���һ��ָ������ڵ��ָ�룬�ȸ�ָ����ָ�����򱣴��������֮���ڽ����ָ�뱣�浽������ 
BiTree CreatTree(){
	BiTree s[MAXSIZE+1],root,q;//ָ�����͵�����ͱ��� 
	//ָ���������ڱ���ڵ�ָ�� 
	int i,j,k,x;
	printf("i,x="); 
	k=scanf("%d,%d",&i,&x);
	printf("%d\n",k);
	printf("%d%d",i,x);
	while(i!=0){
		q=(struct BiTnode*)malloc(sizeof(BiTnode));//����һ���ڵ�ռ� 
		q->data=x;//������ֵ 
		q->lchild=q->rchild=NULL;//ָ����ֵ 
		s[i]=q;//������ַ���浽ָ������ 
		if(i==1){
			root=q;
		}
		j=i/2;//�ýڵ�˫�׵����� 
		if(i/2){//����ڵ��˫�״��� 
			if(i%2){//�����ǰ�ڵ��������ڵ㣬��ô�ýڵ�Ϊ��˫�׽ڵ��������ڵ� 
				s[j]->rchild=q;
			}else{//�����ǰ�ڵ��������ڵ㣬��ô�ýڵ�Ϊ��˫�׽ڵ��������ڵ� 
				s[j]->lchild=q;
			}		
		} 
		printf("i,x=\n"); 
		scanf("%d,%d",&i,&x);	
	} 
	return root;
} 
int main(){
	struct BiTnode *root1;//�½� һ��ָ����������ڵ��ָ�� 
	root1=CreatTree();	
	printf("%d",root1->data);
	printf("%d",root1->lchild->data);
	printf("%d",root1->rchild->data);
}
