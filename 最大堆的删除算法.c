#include<stdio.h>
bool IsEmpty(Heap H)
{
    return H->size==0;
}
ElemType MaxHeapDelete(MaxHeap H)
{
    if(IsEmpty(H))
        return false;
    int x,MaxElem;
    int parent,child;//注意要定义成整型
    MaxElem=H->data[1];//先拿出最大的元素
    x=H->data[H->size--];//将要删除的节点上的元素取出暂存,堆的大小不要忘记减一
    for(parent=1; parent*2<=H->size; parent=child)
    {
        child=2*parent;
        if((child!=H->size)&&(->data[child]<H->data[child+1])) //过滤的时候优先选择大的进行过滤
        {
            child++;
        }
        if(x>H->data[child])
        {
            break;//找到了插入位置
        }
        else
        {
            H->data[parent]=H->data[child];//过滤
        }
    }
    H->data[parent]=x;
    return Maxdata;
}
