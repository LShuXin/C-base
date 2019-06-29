#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
void PercDown(ElemType arr[],int p,int len)
{
    //������len��Ԫ�ص�����arr��������pΪ���ڵ������
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



/*��ʽ�Ķ��������*/
void heapSort(ElemType arr[],int len)
{
    int i,j;
    //���Ƚ�ԭ���齨��������
    for(i=len/2-1; i>=0; i--)
    {
        percDown(arr,i,len);//���������ֱ�ӿ�������ָ��
    }
    //�����ѵ���Ϊ����
    for(i=len-1; i>0; i--)//ע�ⲻ�Ǵ��ڵ���0���Ǵ�����
    {
        //������Ԫ�طŵ������
        swap(&arr[i],&arr[0]);
        percDown(arr,0,i);//���µ������ѣ�ע���ʱ�ѵĴ�С�Ѿ������˱仯����������ֱ�������ָ��

    }
}






