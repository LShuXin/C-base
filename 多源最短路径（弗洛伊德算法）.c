#define true 1
#define false 0
typedef int bool;
typedef int Vertex;
bool Floyd(MGraph Graph; WeightType D[][MaxVertexNum],int path[][MaxVertexNum])
{
//算法的参数三个，第一个参数是用邻接矩阵保存的图，第二个参数与第三个参数是
//一个维数与图的大小相等的二维数组，分别用于存储最短路径的路径长度以及路径
    Vertex i,j,k;
    for(i=0; i<Graph->Nv; i++)
    {
        for(j=0; j<Graph->Nv; j++)
        {
            D[i][j]=Graph->G[i][j];
            path[i][j]=-1;
        }
    }

    for(k=0; k<Graph->Nv; k++)
    {
        for(i=0; i<Graph-Nv; i++)
        {
            for(j=0; j<Graph->Nv; j++)
            {
                if(Graph->G[i][k]+Graph->G[k][j]<Graph->G[i][j])
                {
                    Graph->G[i][j]=Graph->G[i][k]+Graph->G[k][j];
                }
                if(i==j&&Graph->G[i][j]<0)
                {
                    return false;
                }
                path[i][j]=k;
            }
        }
    }
    return true;
}
