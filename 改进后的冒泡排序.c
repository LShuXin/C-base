#include<stdio.h>
#define false 0
#define true 1
typedef int bool;
typedef int ElemType;
void swap(ElemType *a,ElemType *b)
{
    ElemType temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void bubbleSort(ElemType arr[],int len)
{
    int p,i;
    bool flag;
    for(p=len-1; p>=0; p--)
    {
        flag=false;
        for(i=0; i<p; i++)
        {
            if(arr[i]>arr[i+1])
            {
                swap(&arr[i],&arr[i+1]);
                flag=true;
            }
            if(flag==true)
                break;
        }
    }
}
