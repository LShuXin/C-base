#include<stdio.h>
#include<string.h>
typedef int ElemType��
void insertionSort(ElemType arr[],int len)
{
    //����˼·������������Ԫ�ز��������������
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
