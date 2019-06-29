#include<stdio.h>
#include<stdlib.h>
#include<string.h> //使用strlen计算字符数组的大小，当输入的表达式 
#define STACK_INIT_SIZE 100//栈的默认大小
#define STACK_INCREMENT//当栈的大小不够时增加的大小 
#define OK 1
#define ERROR -1
#define OVERFLOW -2 
#define TRUE 1
#define FALSE 0 
typedef int BOOL;//c语言中不存在布尔类型，这里用0,1表示，如果表达式匹配，则返回1，不匹配返回0

typedef char ElemType;
//定义栈的数据结构
typedef struct SqStack{
	ElemType *base;
	int top;
	int stacksize;
}SqStack; 
//SaStack s 可以定义一个栈

void InitStack(SqStack &s){
//栈的初始化算法,传入的是一个栈变量名，使用别名引用	
    s.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));//字符串在栈中是用动态字符串数组来存放的 
    s.top=0;//该种初始化方法，如果栈空，则top=0 
	s.stacksize=STACK_INIT_SIZE; 
} 

int push(SqStack &s,ElemType x) {
	//进栈算法 传入的变量为栈变量与一个字符串变量 对栈的操作使用别名引用 
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
BOOL matchCorrect(/*字符数组指针*/char *ch,/*ch数组中字符串的长度*/int len){
	//函数用于判断表达式中的括号是否匹配，传入一个字符数组指针和表名字符个数的整数，如果匹配返回1 否则返回0

	SqStack s1;//定义一个栈
	InitStack(s1);//初始化栈 
	int i=0,flag;//字符串的索引下标、匹配与否的标志
		for(i=0;i<len;i++){
			printf("%c",ch[i]);
		}
		i=0;  
	    while(i<len){//一直读取到字符
	         printf("%c读取**\n",ch[i]); 
	    	 if(ch[i]=='('||ch[i]=='['||ch[i]=='{') {//如果是开始符号就入栈 
	    	 	push(s1,ch[i]); 
			 }			 
			if(ch[i]==')'){
			   	if(s1.base[s1.top-1]=='('){
			   		pop(s1);//pop函数本身就会将栈顶指针减一*****出过错 
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
	   //如果栈中元素没有了，并且flag=1，表明匹配 
	   if(s1.top==0&&i==len){
	   	    return TRUE;
	   }else{
	        return FALSE;
	   }	
}
int main(){
	int flag=0;
	char ch[100];//一个字符数组，用于存放输入的表达式 
	printf("请输入字符串表达式：\n"); 
	scanf("%s",ch);//读入一个表达式 
	flag=matchCorrect(ch,strlen(ch));
	if(flag==1){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
} 

