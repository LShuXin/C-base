#define MaxVertexNum 100
#define INFINITY 65530
typedef int Vertex;//顶点下标
typedef int WeightType;//假定权重类型为整形
typedef char DataType;//假定顶点的数据类型为字符型
//定义边类型
typedef struct Enode *PtrToEnode;//边的指针类型
typedef struct Enode{
 int v1,v2;//边的两个邻接点
 WeightType weight;//该边的权重
}
typedef PtrToEnode Edge;//边的指针类型
//邻接点类型
typedef struct AdjvNode *PtrToAdjvNode;
typedef struct Adjvnode{
  Vertex Adjv;//邻接点下标
  WeightType weight;//边的权重
  PtrToAdjvNode Next;//指向下一个邻接点的指针
}
//顶点表头结点的定义
typedef struct Vnode{
   PrtToAdjNode FirstEdge;//指向第一个邻接点
   DataType Data;//顶点表头节点存放节点的数据，可无
}AdjList[MaxVertexNum];
//图节点的定义
typedef Gnode *PtrToGnode;
typedef struct Gnode{
    int Nv;//顶点数
    int Ne;//边数
    AdjList G;//邻接表
}
typedef PrtToGnode LGraph;//以邻接表方式存储的图类型

//初始化一个拥有MaxVertexNum 个顶点 ，没有边的图
LGraph CreatLGraph(int MaxVertexNum){
  Vertex v;
  LGraph Graph;
  Graph=(LGraph)malloc(sizeof(Gnode));
  Graph->Ne=0;
  Graph->Nv=MaxVertexNum;
  for(v=0;v<Graph->Nv;v++){
    Graph->G[v].FirstEdge=NULL;
  }
  return Graph;
}
void  InsertEdge(LGraph Graph,Edge E){
   PtrToAdjvNode newnode;
   newnode=(PtrToAdjvNode)malloc(sizeof(AdjvNode));
   newnode->weight=E->weight;
   newnode->Adjv=E->v2;
   newnode->Next=Graph->G[E->v1].FirstEdge;
   Graph->G[E->v1].FirstEdge=newnode;
    return Graph;
}
//建图算法
LGraph BuildGraph(){
 LGraph Graph;
 Edge E;
 int Nv,Ne,i;
 scanf("%d",&Nv);//顶点的数目
 Graph=CreatGraph(Nv);
 scanf("%d",&Ne);//边的数目
 Graph->Ne=Ne;
 if(!Graph->Ne){
    for(i=0;i<Ne;i++){
        scanf("%d%d%d",&(E->v1),&(E->v2),&(E->weight));
        InsertEdge(Graph,E);
    }
 }
 for(i=0;i<Graph->Nv;i++){
    scanf("%c",&(Graph->G[i].Data));
 }
 return Graph;
}
