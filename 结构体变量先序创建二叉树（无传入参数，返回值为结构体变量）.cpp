#include <stdio.h>
#include<stdlib.h>
struct BiTnode{
	char data;
	struct BiTnode *lchild,*rchild;
}*root,*p; 
#define LENG sizeof(BiTnode)
BiTnode CreatBiTree2(){
	struct BiTnode root;
	char ch;
	scanf("%c",&ch)
	if(ch=='0'){
		root=NULL;
	}
	else
	{
		root=(BiTnode)malloc(LENG);
		root->data=ch;
		root->lchild=CreatBiTree2();
		root->rchild=CteatBiTree2();
	}
	return root;
} 
