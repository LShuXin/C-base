//Problem Description
//
//��֪��������һ�����������������ַ����У���abc,,de,g,,f,,, (����,��ʾ�ս��)���뽨�������������������Ҷ�ӽ�������
//Input
//
//��������������ݣ�ÿ����������һ������С��50���ַ����ַ�����
//Output
//
//�����������Ҷ�ӽ�������
//Sample Input
//
//abc,,de,g,,f,,,
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct node{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}Tree;
ElemType str[50];
int i;
int du2num=0;//�����Ϊ���Ľڵ�ĸ������ڶ������У�Ҷ�ӽ�����Ƕ�Ϊ���Ľڵ�����һ���Ӷ�����˶�Ϊ���Ľڵ����Ϳ������Ҷ�ӽ��ĸ��� 
Tree *creat()
{           Tree *tree;
			if(str[i++]==',')
			{
				 tree=NULL;
			}else{
			    tree=(Tree*)malloc(sizeof(Tree));
			    tree->data=str[i-1];
			    tree->lchild=creat();
			    tree->rchild=creat();
			}
			return tree;
} 
void calleaves(Tree *tree){
	if(tree){
		printf("m");
		if(tree->lchild==NULL&&tree->rchild==NULL){
			du2num++;
		}
		calleaves(tree->lchild);
		calleaves(tree->rchild);
	}
}		
		

int main(){
	while(~scanf("%s",str))
	{
		du2num=0;
		i=0;//�����ַ������� 
		Tree *tree=NULL;//����һ���ն����� 
		tree=creat();
		calleaves(tree);
		printf("%d",du2num);
	}	
}

