
#include<stdio.h>
#include<stdlib.h>
#define MAXDATA 65535
#define true 1
//#define false -1
//typedef int bool;
//typedef int ElemType;
//����ѵ����ݽṹ
typedef struct Hnode *Heap;
struct Hnode
{
    ElemType *data;//��Ŷ�Ԫ�صĶ�̬����
    int size;//�ѵĵ�ǰԪ�ظ���
    int capacity;//�ѵ�����ݻ�
};
//ע�⣬��Ԫ������ĵ�һ���ռ�ͨ����ʹ��
typedef Heap  MaxHeap;
typedef Heap MinHeap;
//��������С�ѵĽṹ��ȫһ�£�ֻ�������ߵ�Ԫ������㷨��ͬ
MaxHeap creatMaxHeap(int maxsize)
{
    MaxHeap H=(Heap)malloc(sizeof(Hnode));//�����˶�̬�����ڴ�ռ�
    H->data=(ElemType *)malloc((maxsize+1)*sizeof(ElemType));//��һ����Ԫ����������ڱ�
    H->size=0;
    H->capacity=maxsize;
    H->data[0]=MAXDATA;//!!!��ʼ���ڱ�������
    return H;
}
//�ж϶��Ƿ��Ѿ���
bool IsFull(MaxHeap t)
{
    return t->size==t->capacity;
}
bool InsertMaxHeap(MaxHeap H,ElemType x)
{
    if(IsFull(H))
        return false;
    int i=++H->size;//iָ�����һ��Ԫ�غ�һλ�ã��յģ�
    for(;x>H->data[i/2];i/=2){//���Ϲ���//ע��ǰһ��i/2������
        H->data[i]=H->data[i/2];
    }
    H->data[i]=x;
    return true;
}

