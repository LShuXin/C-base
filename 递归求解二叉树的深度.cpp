#include<stdil.h>
int BiTreeDepth(BiTree root){
	int ldep,rdep,mdep;
	if(root=NULL) return 0;
	ldep=BiTreeDepth(root->lchild);
	rdep=BiTreeDepth(root->rchild);
	mdep=ldep>rdep?ldep:rdep;
	return mdep;
}
int main(){
	
} 	
