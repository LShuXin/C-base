typedef int ElemType
int sequential_line_Search2(ElemType A[],int len,ElemType key)
{
    //改进后的顺序查找
    //将关键字放在根本就不会存放元素的0号索引位置
    //同样是从后向前扫描
    //这样仅需要比较元素是否与关键字相等，而不需要判断索引是否越界
    A[0]=key;
    i=len;
    while(A[i]!=key)
    {
        i--;
    }
    ruturn i;
}

