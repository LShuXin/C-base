void DFS(LGraph Graph,Vertex vertex£¬vois(*Visit)(Vertex)){
 PtrToAdjNode w;
 Visit(vertex);
 Visit[vertex]=true;
for(w=Graph->G[vertex].FirstEdge;w;w=w->Next){
    if(!Visit[w->Adj]){//如果没有被访问
        DFS(Graph,w->Adj,void(*Visit)(Vertex));
    }
}
}
