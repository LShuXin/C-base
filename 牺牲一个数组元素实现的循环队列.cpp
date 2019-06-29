#include<stdio.h>
#define MaxSize 20 //���е���󳤶�
typedef int DataType; //ͨ����������
typedef struct queue
{
	DataType arr[MaxSize];
	int front;
	int rear;	
}Queue; 
//��ʼ������
initQueue(Queue *q)
{
	q->front=0;
    q->rear=0;
 } 
// �ж϶ӿ�
bool IsEmpty(Queue *q)
{
	return q->front==q->rear;
 } 
// �ж϶���
bool IsFull(Queue *q)
{
	return (q->rear+1)%MaxSize==q->front;
 } 
// ���
EnQueue(Queue *q,DataType val)
{
	if(IsFull(q))
	{
		printf("�����������޷����ӣ�");
		return -1;
	}
	else
	{
		q->arr[q->rear]=val;
		q->rear=(q->rear+1)%MaxSize;
	}
 } 
// ����
DataType DeQueue(Queue *q)
{
	if(IsEmpty(q))
	{
		printf("�����ѿգ��޷����ӣ�");
		return -1;
	}
	else
	{
		q->front=(q->front+1)%MaxSize;
	}
 } 
// ���ض�ͷԪ��
DataType FrontQueue(Queue *q)
{
	if(IsEmpty(q))
	{
		printf("�����ѿգ��޷����ض�ͷԪ�أ�");
		return -1;
	}
	else
	{
		return q->arr[q->front];
	}
 } 
 main(){
 }
