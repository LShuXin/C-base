typedef int ElemType
int sequential_line_Search2(ElemType A[],int len,ElemType key)
{
    //�Ľ����˳�����
    //���ؼ��ַ��ڸ����Ͳ�����Ԫ�ص�0������λ��
    //ͬ���ǴӺ���ǰɨ��
    //��������Ҫ�Ƚ�Ԫ���Ƿ���ؼ�����ȣ�������Ҫ�ж������Ƿ�Խ��
    A[0]=key;
    i=len;
    while(A[i]!=key)
    {
        i--;
    }
    ruturn i;
}

