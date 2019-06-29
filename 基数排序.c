#include<stdlib.h>
#define MaxDigit 4
#define Radix 10
typedef int key;
typedef int ElemType;
//�ؼ��ֶ�������
//�ؼ��ֵĸ��������10��
//��10Ϊ�������зֽ�
/*ͰԪ�ؽڵ�*/
typedef struct Node *PtrToNode;
typedef struct Node
{
    int key;
    PtrToNode next;//ͬһ��Ͱ�ϵ�Ԫ�ؽڵ�
};
/*Ͱͷ�ڵ�*/
/*������Ͱͷ�ڵ�Ӧ����10�����ֱ�ָ��ʮ��Ͱ*/
typedef struct HeadNode
{
    PtrToNode head,tail;
};
typedef struct HeadNode Bucket[Radix];
//���ڷ���ָ��λ�õĹؼ��֣��ܹ��У�1,2,3,4��λ�ã�
int GetDigit(int x,int D)
{
//��ǰһ������x�ĵ�Dλ��ȡ���ؼ���d����һλ�ؼ����Ǹ�λ
    int d,i;
    for(i=1; i<=D; i++)
    {
        d=X%Radix;
        X/=Radix;
    }
    return d;
}

//��λ���Ȼ��������㷨
void LSDRadixSort(ElemType A[],int len)
{
    PtrToNode temp,List=NULL,p;
    int D,Di,i;
    Bucket B;

    /*��ʼ��ÿ��ͰΪ������*/
    for(i=1; i<=Radix; i++)
    {
        Bucket[i].head=Bucket[i].tail=NULL;
    }
    /*�����е�Ԫ�����Ȱ������������ռ�����List*/
    for(i=0; i<len; i++)
    {
        temp=(PtrToNode)malloc(sizeof(struct Node));
        temp->key=A[i];
        temp->next=List;
        List->temp;
    }
    //���濪ʼ����
    for(D=1; D<=MaxDigit; D++) /*��ÿһλ����ѭ����������һ��ѭ���Ĵ�*/
    {
        /*�����Ƿ���Ĺ���*/
        p=List;
        while(p)
        {
            temp=p;
            temp->next=NULL;
            p=p->next;
            Di=GetDigit(temp->key,D);

            if(B[Di].head==NULL)
            {
                B[Di].head==B[Di].tail==temp;
            }
            else
            {
                B[Di].tail->next=temp;//������������
                B[Di].tail=temp;//����������
            }
        }
        /*�������ռ��Ĺ���*/
        List=NULL;
        for(Di=Radix-1; i>=0; i++)
        {
            if(B[Di].head)
            {
                B[Di].tail->next=List;
                List=B[Di].head;
                B[Di].tail=B[Di].head=NULL;
            }
        }
    }
    //��list����A���ͷ�List�ռ�
    for(i=0;i<len;i++){
        temp=List;
        List=List->next;
        A[i]=temp->key;
        free(temp);
    }
}




