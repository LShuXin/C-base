#define N 100
#include<stdlib.h>
#include<stdio.h>
typedef int ElemType;
void Merge(ElemType A[],ElemType Temp[],int L,int R,int RightEnd)
{
//�����0-center ��center+1-rightend ���Ѿ���һ�������������潫���Ǻϲ�
    int tem=L,LeftEnd=R-1,i,NumElements;
    NumElemnts=RightEnd-L+1;
    //���ҳ����϶ԳƵĲ������ȹ鲢���
    while((L<=LeftEnd)&&(R<=RightEnd))
    {
        if(A[L]<=A[R])
            Temp[tem++]=A[L++];
        else
            Temp[tem++]=A[R++];
    }
    //ʣ�µ�ֱ�Ӹ���
    while(L<=LeftEnd)
    {
        Temp[tem++]=A[L++];
    }
    while(R<=RightEnd)
    {
        Temp[tem++]=A[R++];
    }
    //�鲢��ɺ��ٸ��Ƶ�ԭ����
    for(i=1; i<=NumElements; i++,RightEnd++)
    {
        A[RightEnd]=Temp[RightEnd];
    }
}

//�鲢������ĵݹ麯��
void MSort(ElemType A[],ElemType Temp[],int L,int RightEnd)
{
    int center=(RightEnd+L)/2;
    //�ݹ������
    MSort(A,Temp,L,Center);
    //�ݹ����ұ�
    MSort(A,Temp,Center+1,RightEnd);
    //�ϲ�
    Merge(A,Temp,L,Center+1,RightEnd);
}
//ͳһ�û��ӿڵĹ鲢�����㷨
void MergeSort(ElemType A,int Len)
{
    ElemType *Temp;
    Temp =(ElemType *)malloc(N*sizeof(ElemType));
    if(Temp!=NULL)
    {
        MSort(A,Temp,L,len-1);
        free(Temp);
    }
    else
    {
        print("�ռ䲻�㣡");
    }
}



