#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define ERROE -1
#define OK 1
#define OVERFLOW -2
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#栈顶指针始终指向后一位置
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
      printf("分配内存失败！");
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
      printf("已空！");
    }
    ElemType e;
    e=obj->base[--obj->top];
}

int minStackTop(MinStack* obj) {
     if(obj->top==0){
        printf("已空！");
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
         printf("已空！");
     }
}

void minStackFree(MinStack* obj) {
    free(obj);
}
