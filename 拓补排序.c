#define true 1
#define false 0
typedef int bool;
bool TopSort(LGraph,Vertex TopOrder[])
{
//��ͼgraph �����ز���������֮��Ķ��㱣����TopOrder��
    WeightType InDegree[MaxVertexNum];//����������
    int i,cnt;
    Vertex v;
    PtrToAdjvNode w;
    Queue Q=CreatQueue(MaxVertexNum);
//�����ж������Ƚ��г�ʼ��
    for(i=0; i<Graph->Nv; i++)
    {
        InDegree[i]=0;
    }
//�������ж����ʵ�����
    for(i=0; i<Graph->Nv; i++)
    {
        for(w=Graph->G.FirstEdge; w; w=w->next)
        {
            InDgree[w=>Adj]++;
        }
    }
//�������Ϊ0�Ķ���������
    for(i=0; i<Graph->Nv; i++)
    {
        if(InDegree[i]==0)
        {
            AddQueue(Q,i);
        }
    }
//���濪ʼ�ز�����
    cnt=0;
    while(!IsEmpty(Q))
    {
        v=DeQueue(Q);
        TopOrder[cnt++]=v;//��������
        for(w=Graph->G[v].FirstEdge; w; w=w->next) //v���ڽӵ����ȼ�һ
        {
            if(--InDegree[w->Adj]==0)
            {
                AddQueue(Q,w-Adj);
            }
        }
    }
    if(cnt!=Graph->Nv)
    {
        return false;
    }
    else
    {
        return true;
    }
}

