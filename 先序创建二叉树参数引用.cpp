struct BiTnode{
	char data;
	struct BiTnode *lchild,*rchild; 
} *root,*p; 
typedef BiTnode *BiTree;
void CreatBiTree3(BiTree &root){
	char ch;
	scanf("%d",&ch);
	if(ch=='0'){
		root=NULL;
	}else{
		root=(BiTree)malloc(sizeof(BiTnode));
		root->data=ch;
		CreatBiTree3(root->lchild);
		CreatBiTree3(root->rchild);
	}	
}
