typedef int ElemType;
//改进后的折半查找，插入查找：Mid=（key-A[Low])*(Heigh-Low)/(A[Heigh]-A[Low])
void HalfSearch2(ElemType A[],int len,ElemType key)
{
    int Low=1,Heigh=len,Mid;
    while(Low<=Heigh)
    {
        //Mid=(Heigh+Low)/2 这是简单折半查找的代码
        Mid=Low+(key-A[Low])*(Heigh-Low)/(A[Heigh]-A[Low]);
        if(A[Mid]<key)
            Low=Mid+1；
                else if(A[Mid]>key)
                    Heigh=Mid-1;
            else
                return Mid；
            }
    return 0;
}
