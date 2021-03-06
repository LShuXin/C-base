#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
void PercDown(ElemType arr[],int p,int len)
{
    //将含有len个元素的数组arr调整成以p为根节点的最大堆
    ElemType x;
    int child,parent;
    X=arr[p];
    for(parent=p; parent*2+1<len; child=parent)
    {
        child=parent*2+1;
        if((child<len-1)&&arr[child]<arr[child+1])
        {
            child++;
        }
        if(arr[parent]>arr[child])
            break;
        else
            arr[parent]=arr[child];
    }
    arr[parent]=x;
}



/*正式的堆排序代码*/
void heapSort(ElemType arr[],int len)
{
    int i,j;
    //首先将原数组建立成最大堆
    for(i=len/2-1; i>=0; i--)
    {
        percDown(arr,i,len);//数组的名字直接可以用作指针
    }
    //将最大堆调整为有序
    for(i=len-1; i>0; i--)//注意不是大于等于0，是大于零
    {
        //将最大的元素放到“最后”
        swap(&arr[i],&arr[0]);
        percDown(arr,0,i);//重新调整最大堆，注意此时堆的大小已经发生了变化；数组的名字本来就是指针

    }
}






