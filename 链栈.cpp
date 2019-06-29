#include <stdlib.h> 
#include <stdio.h>
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define OVERFLOW -2
#define ERROR 0
#define OK 1
typedef int ElemType;
typedef struct {
    ElemType *base;
    int top;
    int stacksize;
} SqStack;
void InitStack(SqStack &S) {
    S.base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    S.stacksize=STACK_INIT_SIZE;
    S.top=0;
}

int Push(SqStack &S, ElemType e) {
     if(S.top>=S.stacksize){
         ElemType *newbase=(ElemType *)realloc(S.base,S.stacksize+STACK_INCREMENT*sizeof(ElemType));
         if(!newbase){
             return ERROR;
         }
         S.base=newbase;
     }
    S.base[S.top]=e;
    S.top++;
}

int Pop(SqStack &S) {
    if(S.top==0){
         return ERROR; 
    }
    ElemType e;
    e=S.base[S.top-1];
    S.top--;
    return OK; 
}

ElemType GetStackTop(SqStack &S) {
     if(S.top==0){
        return OVERFLOW;
     }else{
        return S.base[S.top-1];
     }
    
}

ElemType GetStackMin(SqStack &S) {
     if(S.top!=0){
          ElemType mindata=S.base[0];
          int i=1;
          while(i!=S.top-1){
              if(S.base[i]<mindata)
                 mindata= S.base[i];
              i++;
          }
        return mindata;
     }else{
        return ERROR; 
     }  
}

//void FreeStack(SqStack &S) {
//    free(*S);
//}
int main(){
	SqStack s1;
	InitStack(s1);
	int i;
	for (i=1;i<=200;i++){
		Push(s1,i);
	}
	printf("***********\n");
	for (i=1;i<=200;i++){
		printf("%d",GetStackTop(s1));
		Pop(s1);
	}
	return 0;
}

