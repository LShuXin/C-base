sequential_line_Search1(ElemType A[],int len,ElemType key)
{
//�򵥵�˳�����
//��һ��λ�ò�ʢ��Ԫ��
//ȱ����ÿ�ζ���Ҫ�ȽϺ��ж������ֻ�������
    for(int i=len; i>0; i--)
    {
        if(A[i]==key)
            return i;
    }
    ruturn 0;
}
