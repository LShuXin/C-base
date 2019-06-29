#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define MAXDATA 65535
typedef int ElemType;
typedef struct Hnode *Heap;
typedef struct Hnode
{
    ElemType *data;
    int size;
    int capacity;
}
typedef struct Hnode MinHeap;
typedef struct Hnode MaxHeap;
Heap creatMinHeap(int maxsize)
{
    MinHeap H=(MinHeap)malloc(sizeof(Hnode));
    H->data=(ElemType *)malloc((maxsize+1)*sizeof(ElemType));
    H->data[0]=MAXDATA;
    H->size=0;
    H->capacity=maxsize;
    return H;
}
bool IsFull(Heap H)
{
    return H->size==H->capacity;
}
bool Insert(MinHeap H,ElemType x)
{
    if(IsFull(H))
    {
        return false;
    }
    else
    {
        int i=++H->size;
        for(; x<H->data[i/2]; i/=2)
        {
            H->data[i/2]=H->data[i];
        }
        H->data[i]=x;
        return true;
    }
}
