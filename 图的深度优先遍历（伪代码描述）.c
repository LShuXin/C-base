//Visit[]
// 如何迅速的初始
//Visit 是一个标志顶点是否被遍历·过的数组
//Vertex 是一种数据类型
void DFS(MGraph Graph,Vertex vertex,void(*Visit)(Vertex)){
   Vertex x;
   Visit(vertex);//访问一个顶点
   Visit[vertex]=true;//该顶点已经遍历过了
   for(vertrx 的每一个邻接点x){
    if(!Visit[x){//如果没有被遍历过
        DFS(Graph,x,void(*Visit)(Vertex));
    }
   }
}
