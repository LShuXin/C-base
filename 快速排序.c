typedef int ElemType;
//Ѱ����Ԫ�ĺ���
int Median3(int A[],int right,int left)
{
    //��������������ֱ�Ϊ��һ��Ԫ�������һ��Ԫ�ص�����
    int center=(left+right)/2;//�м�λ��
    if(A[left]>A[center])
        swap(&A[left],&A[right]);
    if(A[center]>A[right])
        swap(&A[center],&A[right]);
    if(A[center]>A[right])
        swap(&A[center],&A[right]);
    //��������ĵ�������һ��λ�ã��м�λ�ã����һ��λ�õ�Ԫ���Ѿ��������
    //��һ��λ�õ�Ԫ�ر�ȻС����Ԫ���м�Ԫ�أ������һ��λ�õ�Ԫ�ر�Ȼ������Ԫ���м�Ԫ�أ�
    //����Ὣ��Ԫ�ŵ������ڶ���λ��
    swap(&A[center],&A[right-1]);
    //���淵����Ԫ���ⲿ
    return A[right-1];
}
void QSort(ElemType A[],int left,int right)
{
    //���ź��ĵݹ麯��
    int Pivot,CutOff,Low,Heigh;
    //��һ�����ڴ���ҵ�����Ԫ���ڶ�����ʾ�������п�����������г�������
    Pivot=media3(A,left,right);
    Low=left;
    Heigh=right-1;
    if((right-left)>=CutOff) //���ÿ�������
    {
        while(1)
        {
            while(A[++Low]<Pivot);
            while(A[--Heigh]>Pivot);
            if(Low<Heigh)
                swap(&A[Low],&A[Heigh]);
            else
                break;
        }

    }
    else  //���ò�������
    {
        InsertionSort(A+left,right-left+1);
    }
}
//ͳһ�ӿ�
void QuickSort(int A[],0,int len)
{
    QSort(A[],0,len-1);
}



