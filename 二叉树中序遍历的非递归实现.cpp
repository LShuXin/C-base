//��������������ķǵݹ�ʵ��
//ԭ�򣺵ݹ�ʵ����д���㣬�������ڴ��������ص�ȱ�㣬�ǵݹ����Ч�ʸ��� 
#include<stdio.h>
#include<stdlib.h>
define MAXLENGTH 50
typedef char ElemType; 
struct BiTnode{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}*root,*p;
void InOrder(struct BiTnode *t){
	//�������ָ��һ�Ŷ��������ڵ��ָ��
	struct BiTnode *st[MAXLENGTH+1];//����һ���ṹ��ָ������
	//����Ϊmaxlength+1��ԭ���ǣ���һ������ռ䲢�����ڴ���
	//δ���ʵĸ���ָ�룬�����ڱ�ʶ�Ƿ���δ���ʵĸ� 
	int top=0;//ָ��δ�����ʵĸ��ġ�ָ�롱
	do{
		while(t){//ѭ����������tΪ���ڵ�������� ������� 
			if(top==MAXLENGTH) exit(OVERFLOW);
		    st[++top]=t;//��������һ��ִ�У��ճ���һ��λ�������ж��Ƿ��и�û�з��� 
		    t=t->lchild;
		} 
		if(top){
			t=st[top--];//ջ��Ԫ�ص�������������ϣ���ջ 
			printf("%c",t->data);//���� 
			t=t->rchild;//���������� 
		}
	} while(top||t)//���и�û�з��ʻ���������δ���� 
		 
} 

