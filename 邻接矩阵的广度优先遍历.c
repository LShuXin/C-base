#define MaxSize 1000
#define INFINITY 65535
#define TRUE 1
#define FALSE 0
bool IsEdge(MGraph Graph,Vertex v,Vertex w){
    return Graph[v][w]==INFINITY;//�ж�ͼ���Ƿ������һ����
}
void BFS(MGraph Graph,Vertex vertex,void(*Visit)(Vertex)){
Queue Q;
Q=CreatQueue(MaxSize);
Vertex v,w;
Visit(vertex);
Visit[vertex]=TRUE;
EnQueue(Q,vertex);
if(IsEmpty(Q)){
    v=DeQueue(Q);
    for(w=0;w<Graph->Nv;w++){
        if(IsEdge(Graph->G[v][w])&&Visit[w]==FALSE){
            Visit(w);
            Visit[w]=TRUE;
            //���������
            EnQueue(Q,w);
        }
    }

}

}
