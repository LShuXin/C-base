#include<stdio.h>
//����������еĽڵ��Ѿ��������˶���
void PercDown(Heap H,int p)
{
//�㷨����H->data[i]Ϊ���Ķѹ��˳�Ϊ��С��
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
        if(x<H->data[parent]) //�ҵ�����λ��
        {
            break;
        }
        else  //�������¹���
        {
            H->data[parent]=H->data[child];
        }
    }
    H->data[parent]=x;
}
