#define N 100
#include<stdlib.h>
#include<stdio.h>
typedef int ElemType;
void Merge(ElemType A[],ElemType Temp[],int L,int R,int RightEnd)
{
//数组的0-center 和center+1-rightend 都已经是一个有序序列下面将他们合并
    int tem=L,LeftEnd=R-1,i,NumElements;
    NumElemnts=RightEnd-L+1;
    //左右长度上对称的部分首先归并完成
    while((L<=LeftEnd)&&(R<=RightEnd))
    {
        if(A[L]<=A[R])
            Temp[tem++]=A[L++];
        else
            Temp[tem++]=A[R++];
    }
    //剩下的直接复制
    while(L<=LeftEnd)
    {
        Temp[tem++]=A[L++];
    }
    while(R<=RightEnd)
    {
        Temp[tem++]=A[R++];
    }
    //归并完成后再复制到原数组
    for(i=1; i<=NumElements; i++,RightEnd++)
    {
        A[RightEnd]=Temp[RightEnd];
    }
}

//归并排序核心递归函数
void MSort(ElemType A[],ElemType Temp[],int L,int RightEnd)
{
    int center=(RightEnd+L)/2;
    //递归解决左边
    MSort(A,Temp,L,Center);
    //递归解决右边
    MSort(A,Temp,Center+1,RightEnd);
    //合并
    Merge(A,Temp,L,Center+1,RightEnd);
}
//统一用户接口的归并排序算法
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
        print("空间不足！");
    }
}



