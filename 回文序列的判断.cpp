#include<stdio.h>
#include<string.h>
#define OVERFLOW -2
#define OK 1
#define ERROR -1
//�ж�һ����@��β���ַ����Ƿ�Ϊ����
//˼·��ͬʱʹ��ջ�Ͷ������ݽṹ
//ȫ�������ַ���֮�� 
//����ջ�����ݽṹ 
int main(){
	//��ʼ��һ��ջ��һ������
	SqStack stack=InitStack();
	SeQueue queue=InitQueue();
	char a,b,c;
	//�������ݣ�ͬʱ���浽ջ�����
	while((c=getchar)!='@'){
		Push(stack,c);
		InQueue(queue,c);
	}
	while(!EmptyStack(stack)){
		a=Pop(stack);
		b=DeQueue(stack);
		if(a!=b){
			printf("�ǻ������У�");
			return ERROR;
		} 
	}
	printf("�ǻ�������"); 
	return 0;
} 
