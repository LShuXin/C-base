
#include<stdio.h>
#include<stdlib.h>
#define MAXDATA 65535
#define true 1
//#define false -1
//typedef int bool;
//typedef int ElemType;
//定义堆的数据结构
typedef struct Hnode *Heap;
struct Hnode
{
    ElemType *data;//存放堆元素的动态数组
    int size;//堆的当前元素个数
    int capacity;//堆的最大容积
};
//注意，堆元素数组的第一个空间通常不使用
typedef Heap  MaxHeap;
typedef Heap MinHeap;
//最大堆与最小堆的结构完全一致，只不过两者的元素添加算法不同
MaxHeap creatMaxHeap(int maxsize)
{
    MaxHeap H=(Heap)malloc(sizeof(Hnode));//忘记了动态分配内存空间
    H->data=(ElemType *)malloc((maxsize+1)*sizeof(ElemType));//第一个单元用作插入的哨兵
    H->size=0;
    H->capacity=maxsize;
    H->data[0]=MAXDATA;//!!!初始化哨兵，忽略
    return H;
}
//判断堆是否已经满
bool IsFull(MaxHeap t)
{
    return t->size==t->capacity;
}
bool InsertMaxHeap(MaxHeap H,ElemType x)
{
    if(IsFull(H))
        return false;
    int i=++H->size;//i指向最后一个元素后一位置（空的）
    for(;x>H->data[i/2];i/=2){//向上过滤//注意前一个i/2，出错
        H->data[i]=H->data[i/2];
    }
    H->data[i]=x;
    return true;
}

