typedef int ElemType;
void shellSort(ElemType arr[],int len)
{
    int D,p,i,si;
    ElemType temp;
//D���ڴ�ŵ�ǰ������
//p�������ѭ��
//i�����ڲ�ѭ��
//si ���������������н�������
//temp������ʱ������Ҫ������ǰ��ȥ������
    ElemType sedgewick[]= {929,505,209,108,41,19,5,1,0};
    for(si=0; sedgewick[si]>=len; si++)
        ;//�������ܴ������е��ܳ��ȣ�����ҪС��
    for(D=sidegwick[si]; D>0; D=sidgewick[++si])
    {
        for(p=D; p<len; p++)//����p+=D�����ʼ����1Ϊ����ѭ��
        {
            temp=arr[p];
            for(i=p; i>=D&&arr[i-D]>temp; i-=D)//i��=D������i>0
            {
                arr[i]=arr[i-d];//���ƽ��Ԫ��
            }
            arr[i]=temp;
        }
    }
}
