#define MaxVertexNum 100 //��󶥵����
#define INFINITY 65535
typedef int Vertex;//�����±�
typedef int WeightType;//�ٶ�Ȩ��Ϊ����
typedef char DataType;//�ٶ�ͼ�ڵ������Ϊ�ַ�
typedef struct Gnode *PtrToGnode;//ָ��ͼ��ָ������
typedef struct Gnode{
   int Ne;//ͼ�Ķ�����
   int Nv;//ͼ�ı���
   WeightType G[MaxVertexNum][MaxVertexNum];//����ߵ�Ȩֵ�����ڽӾ���
   DataType Data[MaxVertexNum];//��Ŷ�������ݣ�������û�����ݣ���data�������Բ�����
}
typedef PtrToGnode MGraph;//�ڽӾ���ͼ���ͣ�ָ������
//�ߵĶ���
typedef struct Enode *PtrToEnode;
typedef struct Enode{
    Vertex  v1,v2;
    Weight weight;
}
//ͼ�ĳ�ʼ���㷨,����һ��ͼ�������������ڽӾ���Ϊ�ա�
MGraph CreatMGraph(int MaxVertexNum){
   MGraph Graph;
   Vertex v,w;
   Graph=(MGraph)malloc(sizeof(Gnode));
   Graph->Nv=MaxVertexNum;
   Graph->Ne=0;
   for(v=0;v<Graph->Nv;v++){
      for(w=0;w<Graph->Nv;w++){
        Graph->G[v][w]=INFINITY;
      }
   }
return Graph;
}
//�ڽӾ����ʾ��ͼ�ıߵĲ����㷨
//����һ��ͼ��һ���ߣ����ز���ߺ��ͼ
//����ͼ�Ĳ����㷨
void InsertEdge(MGraph Graph,Edage E){
    Graph[E->v1][E->v2]=E->weight;
    Graph[E->v2][E->v1]=E->weight;
}
//ͼ�Ľ���
MGraph BuildMGraph(){
    MGraph Graph;
    int Nv,Ne,i;
    Edge E;
    scanf("%d",&Nv);//���붥����Ŀ
    Graph=CreatMGraph(Nv);
    scanf("%d",&Ne);//����ߵ���Ŀ
    Graph->Ne=Ne;
    //�����߹�ϵ����
    if(!Graph->Ne){
        for(i=0;i<Graph->Ne;i++){
         scanf("%d%d%d",&(E->v1),&(E->v2),&(E->weight));
         InsertEdge(Graph,E);
        }
    }
    //���붥������
    if(!Graph->Nv){
        for(i=0;i<G->Nv;i++){
            scanf("%c",&(Graph->Data[i]));
        }
    }
    return Graph;
}







