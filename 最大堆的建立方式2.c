#include<stdio.h>
//���öѽṹ�����е�����Ԫ�ش洢���ٽ��й���
void PercDown(Heap H,int p)
{
    //����h����H->data[p]Ϊ�����ӶѵĶѹ��˳�Ϊ����
    int parent,child;
    ElemType x;
    x=H->data[p];//ǰȡ���Ѷ�Ԫ��
    for(parent=p; 2*parent<=H->size; parent=child) //parent=p �����������Գ���
    {
        child=parent*2;
        if((child<=H->size)&&(H->data[child]<H->data[child+1]))
        {
            child++;
        }
        if(x>H->data[child])
        {
            break;
        }
        else  //���¹���
        {
            H->data[parent]=H->data[child];
        }
    }
    H->data[parent]=x;
}
void BuildHeap(Heap H){
    int i;
    for(i=H->size/2;i>0;i--){
       PercDown(H,i);
    }
}





