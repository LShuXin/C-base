typedef int ElemType;
void HalfSearch(ElemType A[],int len,ElemType key)
{
    //jiandan折半查找
    int Low=1,High=len,Mid;

    while(Low<=High)
    {
        Mid=(High+Low)/2;//位置出错
        if(A[Mid]<key)
            Low=Mid+1;
        else if(A[Mid]>key)
            High=Mid-1;
        else
            return Mid;
    }
    return 0;
}
