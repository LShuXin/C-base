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
    int parent,child;//ע��Ҫ���������
    MaxElem=H->data[1];//���ó�����Ԫ��
    x=H->data[H->size--];//��Ҫɾ���Ľڵ��ϵ�Ԫ��ȡ���ݴ�,�ѵĴ�С��Ҫ���Ǽ�һ
    for(parent=1; parent*2<=H->size; parent=child)
    {
        child=2*parent;
        if((child!=H->size)&&(->data[child]<H->data[child+1])) //���˵�ʱ������ѡ���Ľ��й���
        {
            child++;
        }
        if(x>H->data[child])
        {
            break;//�ҵ��˲���λ��
        }
        else
        {
            H->data[parent]=H->data[child];//����
        }
    }
    H->data[parent]=x;
    return Maxdata;
}
