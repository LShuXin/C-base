#include<stdio.h>
#define MaxSize 20 //队列的最大长度
typedef int DataType; //通用数据类型
typedef struct queue
{
	DataType arr[MaxSize];
	int front;
	int rear;	
}Queue; 
//初始化队列
initQueue(Queue *q)
{
	q->front=0;
    q->rear=0;
 } 
// 判断队空
bool IsEmpty(Queue *q)
{
	return q->front==q->rear;
 } 
// 判断队满
bool IsFull(Queue *q)
{
	return (q->rear+1)%MaxSize==q->front;
 } 
// 入队
EnQueue(Queue *q,DataType val)
{
	if(IsFull(q))
	{
		printf("队列已满！无法进队！");
		return -1;
	}
	else
	{
		q->arr[q->rear]=val;
		q->rear=(q->rear+1)%MaxSize;
	}
 } 
// 出队
DataType DeQueue(Queue *q)
{
	if(IsEmpty(q))
	{
		printf("队列已空，无法出队！");
		return -1;
	}
	else
	{
		q->front=(q->front+1)%MaxSize;
	}
 } 
// 返回队头元素
DataType FrontQueue(Queue *q)
{
	if(IsEmpty(q))
	{
		printf("队列已空，无法返回队头元素！");
		return -1;
	}
	else
	{
		return q->arr[q->front];
	}
 } 
 main(){
 }
