typedef int ElemType;
//寻找主元的函数
int Median3(int A[],int right,int left)
{
    //后面的两个整数分别为第一个元素与最后一个元素的索引
    int center=(left+right)/2;//中间位置
    if(A[left]>A[center])
        swap(&A[left],&A[right]);
    if(A[center]>A[right])
        swap(&A[center],&A[right]);
    if(A[center]>A[right])
        swap(&A[center],&A[right]);
    //经过上面的调整，第一个位置，中间位置，最后一个位置的元素已经有序递增
    //第一个位置的元素必然小于主元（中间元素），最后一个位置的元素必然大于主元（中间元素）
    //下面会将主元放到倒数第二个位置
    swap(&A[center],&A[right-1]);
    //下面返回主元给外部
    return A[right-1];
}
void QSort(ElemType A[],int left,int right)
{
    //快排核心递归函数
    int Pivot,CutOff,Low,Heigh;
    //第一个用于存放找到的主元，第二个表示继续进行快速排序的序列长度下限
    Pivot=media3(A,left,right);
    Low=left;
    Heigh=right-1;
    if((right-left)>=CutOff) //采用快速排序
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
    else  //采用插入排序
    {
        InsertionSort(A+left,right-left+1);
    }
}
//统一接口
void QuickSort(int A[],0,int len)
{
    QSort(A[],0,len-1);
}



