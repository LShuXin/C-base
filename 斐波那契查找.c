typedef int ElemType;
//F��һ��ȫ�ֵ�쳲���������
int Finonacci_search(  ElemType *a,int n,ElemType key)
{
    int high,low,mid,i,k;
    low=1;
    heigh=n;
    k=1;
    while(n>F[k]-1)//�ҵ�쳲����������е�һ��������ĳ��ȴ��Ԫ�ص�λ��
        k++;
    for(i=n; i<F[k]-1; i++)
    {
        a[i]=a[n];//��ԭ��������һ��Ԫ�����
    }
    while(low<=heigh)
    {
        mid=low+F[k-1]-1;//ע�����һ���Ǽ�
        if(key<a[mid])
        {
            heigh=mid-;;
            k--;
        }
        else if(key>a[mid])
        {
            low=mid+1;
            k+=2;
        }
        else
        {
            if(mid<=n)
            {
                return mid;
            }
            else
            {
                return n;
            }
        }
    }
    return 0;
}
