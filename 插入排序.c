#include<stdio.h>
#include<string.h>
typedef int ElemType；
void insertionSort(ElemType arr[],int len)
{
    //总体思路：向后遍历，将元素插入已排序的序列
    int i,p;
    ElemType temp;
    for(p=1; p<len; p++)
    {
        temp=arr[p];
        for(i=p; i>0&&(arr[i]>temp); i++)
        {
            arr[i]=arr[i-1];
        }
        arr[i]=p;
    }
}
