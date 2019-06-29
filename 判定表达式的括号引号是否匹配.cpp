#include<stdio.h>
#include<stdlib.h>
#include<string.h> //ʹ��strlen�����ַ�����Ĵ�С��������ı��ʽ 
#define STACK_INIT_SIZE 100//ջ��Ĭ�ϴ�С
#define STACK_INCREMENT//��ջ�Ĵ�С����ʱ���ӵĴ�С 
#define OK 1
#define ERROR -1
#define OVERFLOW -2 
#define TRUE 1
#define FALSE 0 
typedef int BOOL;//c�����в����ڲ������ͣ�������0,1��ʾ��������ʽƥ�䣬�򷵻�1����ƥ�䷵��0

typedef char ElemType;
//����ջ�����ݽṹ
typedef struct SqStack{
	ElemType *base;
	int top;
	int stacksize;
}SqStack; 
//SaStack s ���Զ���һ��ջ

void InitStack(SqStack &s){
//ջ�ĳ�ʼ���㷨,�������һ��ջ��������ʹ�ñ�������	
    s.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));//�ַ�����ջ�����ö�̬�ַ�����������ŵ� 
    s.top=0;//���ֳ�ʼ�����������ջ�գ���top=0 
	s.stacksize=STACK_INIT_SIZE; 
} 

int push(SqStack &s,ElemType x) {
	//��ջ�㷨 ����ı���Ϊջ������һ���ַ������� ��ջ�Ĳ���ʹ�ñ������� 
	if(s.top>=s.stacksize){
		ElemType *newbase=(ElemType *)realloc(s.base,(STACK_INCREMENT+s.stacksize)*sizeof(ElemType));
		if(!newbase){
		    printf("OVERFLOW!");
		    return ERROR;
	    }
	    s.base=newbase;	
	} 
	s.base[s.top]=x;
	s.top++;
	return OK;
}
int pop(SqStack &s){
	if(s.top==0) {
		return ERROR;
	}else{
		s.top--;
		return OK;
	} 
} 
BOOL matchCorrect(/*�ַ�����ָ��*/char *ch,/*ch�������ַ����ĳ���*/int len){
	//���������жϱ��ʽ�е������Ƿ�ƥ�䣬����һ���ַ�����ָ��ͱ����ַ����������������ƥ�䷵��1 ���򷵻�0

	SqStack s1;//����һ��ջ
	InitStack(s1);//��ʼ��ջ 
	int i=0,flag;//�ַ����������±ꡢƥ�����ı�־
		for(i=0;i<len;i++){
			printf("%c",ch[i]);
		}
		i=0;  
	    while(i<len){//һֱ��ȡ���ַ�
	         printf("%c��ȡ**\n",ch[i]); 
	    	 if(ch[i]=='('||ch[i]=='['||ch[i]=='{') {//����ǿ�ʼ���ž���ջ 
	    	 	push(s1,ch[i]); 
			 }			 
			if(ch[i]==')'){
			   	if(s1.base[s1.top-1]=='('){
			   		pop(s1);//pop��������ͻὫջ��ָ���һ*****������ 
				}else{
				   flag=0;
				   break; 
				} 
			}
			if(ch[i]==']'){
			   	if(s1.base[s1.top-1]=='['){
			   		pop(s1);
				}else{
				   	flag=0;
				   	break;
				   }
			}
			if(ch[i]=='}'){
			   	if(s1.base[s1.top-1]=='{'){
			   		pop(s1);
				}else{
				   	flag=0;
				   	break;
				}
			} 
			i++; 
		}
	   //���ջ��Ԫ��û���ˣ�����flag=1������ƥ�� 
	   if(s1.top==0&&i==len){
	   	    return TRUE;
	   }else{
	        return FALSE;
	   }	
}
int main(){
	int flag=0;
	char ch[100];//һ���ַ����飬���ڴ������ı��ʽ 
	printf("�������ַ������ʽ��\n"); 
	scanf("%s",ch);//����һ�����ʽ 
	flag=matchCorrect(ch,strlen(ch));
	if(flag==1){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
} 

