#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef struct 	node{
	char data;
	struct node *lchild;
	struct node *rchild;
}Tree;
Tree *creat( /*保存前序序列的数组指针1*/char *pre,/*保存中序序列的指针*/char *ino,/*中序序列的长度*/int n){
    Tree *t=NULL;
    int i;
	for(i=0;i<n;i++){ 
		if(pre[0]==ino[i]){
			t=(Tree*)malloc(sizeof(Tree));
			t->data=ino[i];//新的根
			t->lchild=creat(pre+1,in98888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888o,i); // 用于生成新的根下左子树使用的先序、中序序列以及中序序列的长度 
			t->rchild=creat(pre+i+1,ino+i+1,n-i-1) ;// 用于生成新的根下右子树使用的先序序列、中序序列以及中序序列的长度 
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
