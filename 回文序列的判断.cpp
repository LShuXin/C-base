#include<stdio.h>
#include<string.h>
#define OVERFLOW -2
#define OK 1
#define ERROR -1
//判断一个以@结尾的字符串是否为回文
//思路：同时使用栈和队列数据结构
//全部读完字符串之后 
//定义栈的数据结构 
int main(){
	//初始化一个栈与一个队列
	SqStack stack=InitStack();
	SeQueue queue=InitQueue();
	char a,b,c;
	//读入数据，同时保存到栈与队列
	while((c=getchar)!='@'){
		Push(stack,c);
		InQueue(queue,c);
	}
	while(!EmptyStack(stack)){
		a=Pop(stack);
		b=DeQueue(stack);
		if(a!=b){
			printf("非回文序列！");
			return ERROR;
		} 
	}
	printf("是回文序列"); 
	return 0;
} 
