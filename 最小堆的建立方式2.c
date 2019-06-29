#include<stdio.h>
//这里假设所有的节点已经保存在了堆中
void PercDown(Heap H,int p)
{
//算法将以H->data[i]为根的堆过滤成为最小堆
    int parent,child;
    ElemType x;
    x=H->data[p];
    for(parent=p; 2*parent<=H->size; parent=child)
    {
        child=2*parent;
        if((child<H->size)&&(H->data[child]>H->data))
        {
            child++;
        }
        if(x<H->data[parent]) //找到合适位置
        {
            break;
        }
        else  //继续向下过滤
        {
            H->data[parent]=H->data[child];
        }
    }
    H->data[parent]=x;
}
