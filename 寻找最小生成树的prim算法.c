#define ERROR -1
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;
Vertex FindMinVertex(Mgraph Graph,WeightType dist[])
{
//传入两个参数，第一个参数是一个用邻接矩阵保存的图，第二个参数是一个长度与前述图顶点个数相等的一维数组，
//保存图的每个顶点到当前数的最短距离，
//如果顶点与当前树有路径（一条边），那么数组保存该顶点到当前树的最短路径（一条边权重）
//如果顶点已经在当前树中了，那么权重为
//如果顶点与当前树不存在一条边相连接，那么权重为无穷大
    Vertex MinV,v;
    WeightType MinDist=INFINITY;
    for(v=0; v<Grapn->Nv; v++)
    {
        if(dist[v]!=0&&dist[v]<INFINITY)
        {
            if(dist[v]<MinDist)
            {
                MinDist=dist[v];
                MinV=v;
            }
        }
    }
    if(MinDist<INFINITY)
        return MinV;
    else
        return ERROR;
}
int Prim(MGraph Graph)
{
    Vertex v,w,parent[Graph->Nv];
    weightType dist[Graph->Nv],TotalWeight;
    LGraph MST;
    int VCount=0;
    Edge E=(Edge)malloc(sizeof(struct Enode));
    for(v=0; v<Graph->Nv; v++)
    {
        //首先以0为当前树的根
        parent[v]=0;
        dist[v]=Graph[0][v];
    }
    dist[0]=0;
    parent[0]=-1;
    VCount++;
    TotalWeight=0;

    while(1)
    {
        v=FindMinVertex(Graph,dist);
        if(v==ERROR)
        {
            break;
        }
        E->v1=parent[v];
        E->v2=v;
        E->weight=dist[v];
        InsertEdge(MST,E);
        Vcount++;
        TotalWeight+=E->weight;
        for(w=0; w<Graph->Nv; w++)
        {
            if(dist[w]!=0&&Graph[v][w]<INFINITY)
            {
                if(Graph[v][w]<dist[w])
                {
                    dist[w]=Graph[v][w];
                    parent[w]=v;
                }
            }
        }
    }
    if(VCount==Graph->Nv)
    {
        return TotalWeight;
    }
    else
    {
        return ERROR;
    }






}
