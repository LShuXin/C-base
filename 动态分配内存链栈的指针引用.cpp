#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define ERROR -1
#define OK 1
#define OVERFLOW -2
#include <stdio.h>
#include <stdlib.h>
//��������������� 
typedef int ElemType;
//������ջ�ṹ�� 
typedef struct {
    ElemType *base;//���ջ��Ԫ�ص����� 
    int top;//ջ��ָ�룬ʼ��ָ��ջ��Ԫ�ص���һλ�� 
    int stacksize;//��ջջ��ʱ�Ĵ�С 
} MinStack;//�ṹ����� 

/*��ʼ����ջ�ĺ���������ָ����ʽջ��ָ��*/
MinStack* minStackCreate(int maxSize) {
    MinStack *S;//��ջָ�� 
    S=(MinStack*)malloc(sizeof(MinStack));//Ϊ��ջ�����ڴ� 
    S->base=(int*)malloc(maxSize*sizeof(int));//Ϊ��ջ��������������ڴ� 
    if(!S->base){//��������ڴ治�ɹ� 
      perror("malloc");//�������������ԭ���������׼�豸(
      exit(EXIT_FAILURE);//��������˳� 
    }else{
      S->stacksize=maxSize;
      S->top=0;
      return S;
	} 
   
}
//��ջ�ĺ��� 
void minStackPush(MinStack* obj, int x) {
    if(obj->top>=obj->stacksize){//���ջ��ָ���Ѿ�ָ����ջ����Ԫ��
	//Ϊ�˼�������վ��ָ��ʼ��ָ��ջ��Ԫ�ص���һλ�õ�Լ������Ҫ���¿����ڴ� 
    	ElemType *newbase;
		newbase=(ElemType*)realloc(obj->base,(obj->stacksize+STACK_INCREMENT)*sizeof(ElemType));
        if(!newbase){
		    //��������ڴ�ʧ�����쳣�˳�
        	printf("OVERFLOW");
        	exit(EXIT_FAILURE); 
		}else{
			//�ɹ������ڴ� 
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
        // printf("\nջ��Ϳ���\n");
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
	//���Դ��� 
   MinStack *S=minStackCreate(STACK_INIT_SIZE); 
   //��ջ 
   int i=1;
   while(i<=205){
   	     minStackPush(S, i);
   	     i++;
   }
   printf("\n���ջ��Ԫ�أ�");
   //��ӡջ��Ԫ�� 
   
   while(S->top>=1){
   	 printf("%d ",S->base[--S->top]);
   } 

//��ջ���� 
//   minStackPop(S);	
} 

