#include <stdio.h>
typedef int ElemType
/*ջ������ʵ��*/
//����ڵ�ṹ
typedef struct node{
    ElemType data;
    struct node *next;
}node *Top;
//��ջ����
struct node *LStackPush(struct node *top,ElemType e){
    struct node *p;//����ָ��ṹ��ڵ��ָ��
    p=(struct node*)malloc(sizeof(struct node));//���ݽṹ��Ĵ�С�����ڴ�ռ�
    p->data=e;//������д��
    p-next=top;//��ջ���ڵ������ջ��
    top=p;//�����µ�վ��ָ�룬ע��ջ��ָ��������ֱ��ָ��ջ��Ԫ�ص�
    return top;//����ջ��ָ��
}
//��վ����
struct node *LinkStackPop(struct node *top){
    //�������һ��ջ��ָ�룬���ص���һ��ɾ����ջ��Ԫ��֮���ָ���µ�ջ����ָ��
    if(top==NULL){
        exit(EXIT_FAILURE);//����������һ����ָ�룬��˵��ջ�ѿգ������˳�
    }else{
        top=top->next;//��topָ��ջ��Ԫ�ص���һ��Ԫ��
        reurn top;//����ȥ��ջ��Ԫ��֮����µ�ջ��Ԫ�ص�ָ��
    } 
}

bool isValid(char* s) {
    
    
}
