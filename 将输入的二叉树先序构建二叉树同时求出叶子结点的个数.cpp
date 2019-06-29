//Problem Description
//
//已知二叉树的一个按先序遍历输入的字符序列，如abc,,de,g,,f,,, (其中,表示空结点)。请建立二叉树并求二叉树的叶子结点个数。
//Input
//
//连续输入多组数据，每组数据输入一个长度小于50个字符的字符串。
//Output
//
//输出二叉树的叶子结点个数。
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
int du2num=0;//保存度为二的节点的个数，在二叉树中，叶子结点数是度为二的节点数加一，从而求出了度为二的节点数就可以求出叶子结点的个数 
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
		i=0;//遍历字符的索引 
		Tree *tree=NULL;//创建一个空二叉树 
		tree=creat();
		calleaves(tree);
		printf("%d",du2num);
	}	
}

