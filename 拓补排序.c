#define true 1
#define false 0
typedef int bool;
bool TopSort(LGraph,Vertex TopOrder[])
{
//对图graph 进行拓补排序，排序之后的顶点保存在TopOrder中
    WeightType InDegree[MaxVertexNum];//各顶点的入度
    int i,cnt;
    Vertex v;
    PtrToAdjvNode w;
    Queue Q=CreatQueue(MaxVertexNum);
//对所有顶点的入度进行初始化
    for(i=0; i<Graph->Nv; i++)
    {
        InDegree[i]=0;
    }
//计算所有顶点的实际入度
    for(i=0; i<Graph->Nv; i++)
    {
        for(w=Graph->G.FirstEdge; w; w=w->next)
        {
            InDgree[w=>Adj]++;
        }
    }
//所有入度为0的顶点进入队列
    for(i=0; i<Graph->Nv; i++)
    {
        if(InDegree[i]==0)
        {
            AddQueue(Q,i);
        }
    }
//下面开始拓补排序
    cnt=0;
    while(!IsEmpty(Q))
    {
        v=DeQueue(Q);
        TopOrder[cnt++]=v;//加入序列
        for(w=Graph->G[v].FirstEdge; w; w=w->next) //v的邻接点的入度减一
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

