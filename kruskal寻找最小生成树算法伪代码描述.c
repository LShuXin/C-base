int KrusKal(LGraph Graph,LGraph MST)
{
    /*����С���������浽MST�в��ҷ�����СȨ�غ�*/
    MST=������ԭͼ���еĶ��㵫������ߵ�ͼ��
        while(MST�к��еı�������Graph-Nv-1&&ԭͼ�еı߼�E�ǿ�)
    {
        ��E���ҳ���С���۱�(v,w);
        ��E��ɾ���˱�(v,w);
        if((v,w)����MST�й��ɻ�·)
        {
            ��(v,w)����MST;
        }
        else
        {
            E�����õ�ɾ��(v,w);
        }
    }
    if(MST���ռ��ı�������Graph->Nv-)
    {
        return ERROR;
    }
    else
    {
        return ERROR;
    }
}
