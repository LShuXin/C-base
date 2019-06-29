#define MaxVertexNum 100
#define INFINITY 65530
typedef int Vertex;//�����±�
typedef int WeightType;//�ٶ�Ȩ������Ϊ����
typedef char DataType;//�ٶ��������������Ϊ�ַ���
//���������
typedef struct Enode *PtrToEnode;//�ߵ�ָ������
typedef struct Enode{
 int v1,v2;//�ߵ������ڽӵ�
 WeightType weight;//�ñߵ�Ȩ��
}
typedef PtrToEnode Edge;//�ߵ�ָ������
//�ڽӵ�����
typedef struct AdjvNode *PtrToAdjvNode;
typedef struct Adjvnode{
  Vertex Adjv;//�ڽӵ��±�
  WeightType weight;//�ߵ�Ȩ��
  PtrToAdjvNode Next;//ָ����һ���ڽӵ��ָ��
}
//�����ͷ���Ķ���
typedef struct Vnode{
   PrtToAdjNode FirstEdge;//ָ���һ���ڽӵ�
   DataType Data;//�����ͷ�ڵ��Žڵ�����ݣ�����
}AdjList[MaxVertexNum];
//ͼ�ڵ�Ķ���
typedef Gnode *PtrToGnode;
typedef struct Gnode{
    int Nv;//������
    int Ne;//����
    AdjList G;//�ڽӱ�
}
typedef PrtToGnode LGraph;//���ڽӱ�ʽ�洢��ͼ����

//��ʼ��һ��ӵ��MaxVertexNum ������ ��û�бߵ�ͼ
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
//��ͼ�㷨
LGraph BuildGraph(){
 LGraph Graph;
 Edge E;
 int Nv,Ne,i;
 scanf("%d",&Nv);//�������Ŀ
 Graph=CreatGraph(Nv);
 scanf("%d",&Ne);//�ߵ���Ŀ
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
