#include <stdio.h>
#include<stdlib.h>
void swap(ElemType *a,ElemType *b)
{
    ElemType t=*a;
    *a=*b;
    *b=t;
}
void simpleSelectSort(ElemType arr[],int len)
{
    int i,j,min;
    for(i=0; i<len-i; i++)
    {
        min=i;
        for(j=i+1; j<len; j++)
        {
            if(arr[j]<arr[i])
                min=j;
        }
        swap(&arr[min],&arr[i]);
    }
}
