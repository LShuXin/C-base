sequential_line_Search1(ElemType A[],int len,ElemType key)
{
//简单的顺序查找
//第一个位置不盛放元素
//缺点是每次都需要比较和判断这两种基本操作
    for(int i=len; i>0; i--)
    {
        if(A[i]==key)
            return i;
    }
    ruturn 0;
}
