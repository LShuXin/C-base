//二叉树中序遍历的非递归实现
//原因：递归实现书写方便，但存在内存消耗严重的缺点，非递归调用效率更高 
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
	//传入的是指向一颗二叉树根节点的指针
	struct BiTnode *st[MAXLENGTH+1];//定义一个结构体指针数组
	//长度为maxlength+1的原因是，第一个数组空间并不用于储存
	//未访问的根的指针，仅用于标识是否还有未访问的根 
	int top=0;//指向未经访问的根的“指针”
	do{
		while(t){//循环结束，以t为根节点的左子树 遍历完成 
			if(top==MAXLENGTH) exit(OVERFLOW);
		    st[++top]=t;//考虑语句第一次执行，空出第一个位置用于判断是否还有根没有访问 
		    t=t->lchild;
		} 
		if(top){
			t=st[top--];//栈顶元素的左子树遍历完毕，退栈 
			printf("%c",t->data);//访问 
			t=t->rchild;//遍历右子树 
		}
	} while(top||t)//当有根没有访问或者右子树未访问 
		 
} 

