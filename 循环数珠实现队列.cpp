#define MaxSize 20//定义队列的最大长度 
#include<stdio.h>
typedef int DataType; //复杂的声明定义简单的别名
//定义队列结构体 
typedef struct queue
{
	DataType arr[MaxSize];
    int front;
    int rear;
    int counter;
}Queue;
//初始化队列
Init(Queue *q)
{
    q->front=0;
    q->rear=0;
    q->counter=0;
} 
//判断队列为空
bool IsEmpty(Queue *q)
{
	return q->counter==0;
} 
//判断队满
bool IsFull(Queue *q)
{
	return q->counter==MaxSize;
} 
//入队
void Enqueue(Queue *q,DataType val)
{
	if(IsFull(q))
	{
	    printf("\n队已满\n");
	    return;
    }
    else
    {
    	q->rear=(q->rear+1)%MaxSize;
    	q->arr[q->rear]=val;
    	q->counter++;
//    		对于有counter的队列，进队时，rear先后移，在对其指向的存储节点赋值 
    }
}
//出队
void DeQueue(Queue *q)
{
	if(IsEmpty(q))
	{
		printf("队空，无法出队！");
		return; 
	}
	else
	{
		q->front=(q->front+1)%MaxSize;
		q->counter--;
		
	}
 } 
// #取队首元素
DataType FrontQueue(Queue *q)
{
	if(IsEmpty(q))
	{
		printf("\n队列为空，无法返回队头元素！\n");
		return -1;
	}
	else{
		return q->arr[q->front];
	}
 }    

main(){
//	注意：MaxSize不要定义成队列结构的的成员
//MaxSize用宏定义即可
//用“typedef 数据类型  自定义数据类型标识符”对通用队列数据类型进行定义 
 
} 
