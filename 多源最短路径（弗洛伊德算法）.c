#define true 1
#define false 0
typedef int bool;
typedef int Vertex;
bool Floyd(MGraph Graph; WeightType D[][MaxVertexNum],int path[][MaxVertexNum])
{
//�㷨�Ĳ�����������һ�����������ڽӾ��󱣴��ͼ���ڶ��������������������
//һ��ά����ͼ�Ĵ�С��ȵĶ�ά���飬�ֱ����ڴ洢���·����·�������Լ�·��
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
