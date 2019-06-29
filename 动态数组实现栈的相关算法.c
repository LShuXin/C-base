#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define ERROE -1
#define OK 1
#define OVERFLOW -2
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#ջ��ָ��ʼ��ָ���һλ��
typedef struct {
    ElemType *base;
    int top;
    int stacksize;
} MinStack;

MinStack* minStackCreate(int maxSize) {
    MinStack *S;
    S=(MinStack*)malloc(sizeof(MinStack));
    S->base=(ElemType*)malloc(maxSize*sizeof(ElemType));
    if(!S->base){
      exit(-1);
      printf("�����ڴ�ʧ�ܣ�");
    }
    S->stacksize=maxSize;
    S->top=0;
    return S;
}

void minStackPush(MinStack* obj, int x) {
    if(!obj->base){
        obj->base[obj->top]=x;
        obj->top++;
    }

}

void minStackPop(MinStack* obj) {
    if(obj->top==0){
      printf("�ѿգ�");
    }
    ElemType e;
    e=obj->base[--obj->top];
}

int minStackTop(MinStack* obj) {
     if(obj->top==0){
        printf("�ѿգ�");
     }else{
        return obj->base[obj->top-1];
    }
}

int minStackGetMin(MinStack* obj) {
    if(obj->top!=0){
          ElemType mindata=obj->base[0];
          int i=1;
          while(i!=obj->top-1){
              if(obj->base[i]<mindata)
                 mindata= obj->base[i];
              i++;
          }
        return mindata;
    }else{
         printf("�ѿգ�");
     }
}

void minStackFree(MinStack* obj) {
    free(obj);
}
