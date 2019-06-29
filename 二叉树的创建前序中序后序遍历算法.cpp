#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char data;
    struct node *Lchild, *Rchild;
}BiTree;
char s[51];
int i=0;
BiTree *creat(){
	BiTree *t;
    if(s[i++] == ','){
        printf("%c", s[i-1]);
    	t=NULL;
	}else{	
        t = (BiTree*) malloc(sizeof(BiTree));
        t->data = s[i-1];
        t->Lchild= creat();
        t->Rchild= creat();
    }
    return t;
}
InOrder(BiTree *t)
{
	 printf("%c", t -> data);
    if(t)
    {
        InOrder(t -> Lchild);
        printf("%c", t -> data);
        InOrder(t -> Rchild);
    }
}
PostOrder(BiTree  *t)
{

    if(t)
    {
        PostOrder(t -> Lchild);
        PostOrder(t -> Rchild);
        printf("%c", t -> data);
    }
}
int main()
{  
    while(~scanf("%s", s))
    {
    	printf(strlen(s));
        BiTree *tree;
        tree = creat();
        InOrder(tree);
        printf("\n");
        PostOrder(tree);
        printf("\n");
    }
    return 0;
}

