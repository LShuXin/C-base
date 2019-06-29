//队列的顺序存储（循环队列）
#include<stdio.h>
#define MAXLENG 10
#define OK 1
#define ERROR -1
#define OVERFLOW -2
typedef int ElemType;
//定义顺序队列的结构
typedef struct{
	ElemType elem[MAXLENG];
	int rear,front;//队列的头“指针”与尾“指针” 
	//头指针直接指向队头元素
	//尾指针指向队尾元素的后一个位置，以标识队满与栈空
    //队满的条件(rear+1)%maxleng=front
    //队列空的条件 front ==rear	
}SeQueue;

//循环队列的初始化算法
SeQueue InitQueue(){
	SeQueue s;
	s.front=s.rear=0; 
	return s;
} 
//循环队列的进队算法
int InQueue(SeQueue &Q,ElemType e){
	//函数传入两个参数
    //第一个参数是一个队列变量名
    //第二个参数是要插入的元素 
    //返回进队成功与否
	if((Q.rear+1)%MAXLENG==Q.front){
	    printf("队列已满！\n");
		return 	OVERFLOW; 
	}else{
		//因为本来队尾指针就指向了队尾元素的后一位置
		//因此入队时，先在队尾指针的位置 插入元素，再把队尾指针向后移动一个位置 
		Q.elem[Q.rear++]=e;
		printf("%d 已经入队\n",e);
		return OK;
	}
}
//循环队列出队算法
int DeQueue(SeQueue &Q,ElemType *e){//变量的参数引用*******没写取地址符号出错 
	//循环队列的出队算法传入两个参数
	//第一个参数是要出队的队列的名字
	//第二个参数是用于保存出队元素的指针
	//队列的引用采取参数引用
	if(Q.rear==Q.front){ 
		printf("队列已空，无法出队！");
		return OVERFLOW; 	
    }else{//直接将队头指针加一 
        printf("出队的头指针是：%d",Q.front);
        (*e)=Q.elem[Q.front];
        Q.front=(Q.front+1)%MAXLENG;////******************直接加一出错 
        printf("出队后的头指针是：%d",Q.front);
		return OK; 
    }
}
int main(){
	int i,e;
	SeQueue s1=InitQueue();
	//进队 
	for(i=1;i<12;i++){
		InQueue(s1,i*i);
	}
	//出队
    for(i=0;i<12;i++){
		DeQueue(s1,&e);
		printf("   %d已经出队\n",e);
	}
	return 0;
}
