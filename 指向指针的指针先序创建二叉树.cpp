#include<stdio.h>
#include<stdlb.h>
struct BiTnode{
	char data;
	struct BiTnode *lchild;
	struct BiTnode *rchild;
}*root,*p; 
#define leng sizeof(BiTnode)//�ڵ�ռ��С
void CreatBiTree1(struct BiTnode **root){
	//����Ĳ�����ָ��������ڵ��ָ��ĵ�ַ
	char ch;
	scanf("%c",&ch);
	if(ch=="0")
	{
	    (*root)=NULL;//�ڵ�Ϊ��
	} 
	else
	{
	    (*root)=(struct BiTnode*)malloc(leng);//����ڵ��ڴ�ռ�
		(*root)->data=ch;
		CreatBiTree1(&(*root)->lchild);//�ݹ鴴�������� 
		CreatBiTree1(&(*root)->lchild);//�ݹ鴴�������� 
	}
} 
