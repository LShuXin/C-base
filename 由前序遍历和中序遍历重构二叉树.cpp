#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef struct 	node{
	char data;
	struct node *lchild;
	struct node *rchild;
}Tree;
Tree *creat( /*����ǰ�����е�����ָ��1*/char *pre,/*�����������е�ָ��*/char *ino,/*�������еĳ���*/int n){
    Tree *t=NULL;
    int i;
	for(i=0;i<n;i++){ 
		if(pre[0]==ino[i]){
			t=(Tree*)malloc(sizeof(Tree));
			t->data=ino[i];//�µĸ�
			t->lchild=creat(pre+1,in98888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888o,i); // ���������µĸ���������ʹ�õ��������������Լ��������еĳ��� 
			t->rchild=creat(pre+i+1,ino+i+1,n-i-1) ;// ���������µĸ���������ʹ�õ��������С����������Լ��������еĳ��� 
		    return t;
		}
	} 	
}

PostOrder(Tree *tree){
	if(tree){
		PostOrder(tree->lchild);	
		PostOrder(tree->rchild);
		printf("%c",tree->data);
	}
}
int main(){
	int len;
	char pre[10];
	char ino[10];
	scanf("%s",pre);
	scanf("%s",ino);
	len=strlen(ino);
	Tree *tree=creat(pre,ino,len);
	PostOrder(tree);
	return 0;	
}
