#define MaxSize 20//������е���󳤶� 
#include<stdio.h>
typedef int DataType; //���ӵ���������򵥵ı���
//������нṹ�� 
typedef struct queue
{
	DataType arr[MaxSize];
    int front;
    int rear;
    int counter;
}Queue;
//��ʼ������
Init(Queue *q)
{
    q->front=0;
    q->rear=0;
    q->counter=0;
} 
//�ж϶���Ϊ��
bool IsEmpty(Queue *q)
{
	return q->counter==0;
} 
//�ж϶���
bool IsFull(Queue *q)
{
	return q->counter==MaxSize;
} 
//���
void Enqueue(Queue *q,DataType val)
{
	if(IsFull(q))
	{
	    printf("\n������\n");
	    return;
    }
    else
    {
    	q->rear=(q->rear+1)%MaxSize;
    	q->arr[q->rear]=val;
    	q->counter++;
//    		������counter�Ķ��У�����ʱ��rear�Ⱥ��ƣ��ڶ���ָ��Ĵ洢�ڵ㸳ֵ 
    }
}
//����
void DeQueue(Queue *q)
{
	if(IsEmpty(q))
	{
		printf("�ӿգ��޷����ӣ�");
		return; 
	}
	else
	{
		q->front=(q->front+1)%MaxSize;
		q->counter--;
		
	}
 } 
// #ȡ����Ԫ��
DataType FrontQueue(Queue *q)
{
	if(IsEmpty(q))
	{
		printf("\n����Ϊ�գ��޷����ض�ͷԪ�أ�\n");
		return -1;
	}
	else{
		return q->arr[q->front];
	}
 }    

main(){
//	ע�⣺MaxSize��Ҫ����ɶ��нṹ�ĵĳ�Ա
//MaxSize�ú궨�弴��
//�á�typedef ��������  �Զ����������ͱ�ʶ������ͨ�ö����������ͽ��ж��� 
 
} 
