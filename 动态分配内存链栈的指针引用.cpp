#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define ERROR -1
#define OK 1
#define OVERFLOW -2
#include <stdio.h>
#include <stdlib.h>
//定义抽象数据类型 
typedef int ElemType;
//定义链栈结构体 
typedef struct {
    ElemType *base;//存放栈中元素的数组 
    int top;//栈顶指针，始终指向栈顶元素的上一位置 
    int stacksize;//该栈栈满时的大小 
} MinStack;//结构体变量 

/*初始化链栈的函数，返回指向链式栈的指针*/
MinStack* minStackCreate(int maxSize) {
    MinStack *S;//链栈指针 
    S=(MinStack*)malloc(sizeof(MinStack));//为链栈分配内存 
    S->base=(int*)malloc(maxSize*sizeof(int));//为链栈的数据数组分配内存 
    if(!S->base){//如果分配内存不成功 
      perror("malloc");//函数发生错误的原因输出到标准设备(
      exit(EXIT_FAILURE);//程序错误退出 
    }else{
      S->stacksize=maxSize;
      S->top=0;
      return S;
	} 
   
}
//进栈的函数 
void minStackPush(MinStack* obj, int x) {
    if(obj->top>=obj->stacksize){//如果栈顶指针已经指向了栈顶单元格
	//为了继续保持站顶指针始终指向栈顶元素的上一位置的约定，需要重新开辟内存 
    	ElemType *newbase;
		newbase=(ElemType*)realloc(obj->base,(obj->stacksize+STACK_INCREMENT)*sizeof(ElemType));
        if(!newbase){
		    //如果分配内存失败则异常退出
        	printf("OVERFLOW");
        	exit(EXIT_FAILURE); 
		}else{
			//成功分配内存 
			free(obj->base);
			obj->base=newbase;
			obj->stacksize+=STACK_INCREMENT;
			printf("newstacksize:%dbytes\n",obj->stacksize);
		}
	}
    obj->base[obj->top]=x;
    obj->top++;  
    printf("pushed\n");
}
void minStackPop(MinStack* obj) {
	//printf("\nbefor pop,top pointer is %d",obj->top);
    if(obj->top==0){
        // printf("\n栈早就空了\n");
       	exit(EXIT_FAILURE);
    }else{
        //    ElemType e;
        //    e=obj->base[obj->top-1]; 
        //    printf("\nelement %d has been popped!",e);
        obj->top--;	
        //    printf("\nnow top pointer is %d",obj->top);
	} 
}

int minStackTop(MinStack* obj) {
     if(obj->top==0){
        return ERROR; 
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
          return ERROR; 
     }  
}
void minStackFree(MinStack* obj) {
     free(obj);  
}
int main(){
	//测试代码 
   MinStack *S=minStackCreate(STACK_INIT_SIZE); 
   //入栈 
   int i=1;
   while(i<=205){
   	     minStackPush(S, i);
   	     i++;
   }
   printf("\n输出栈内元素：");
   //打印栈内元素 
   
   while(S->top>=1){
   	 printf("%d ",S->base[--S->top]);
   } 

//出栈测试 
//   minStackPop(S);	
} 

