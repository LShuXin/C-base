//Visit[]
// ���Ѹ�ٵĳ�ʼ
//Visit ��һ����־�����Ƿ񱻱�������������
//Vertex ��һ����������
void DFS(MGraph Graph,Vertex vertex,void(*Visit)(Vertex)){
   Vertex x;
   Visit(vertex);//����һ������
   Visit[vertex]=true;//�ö����Ѿ���������
   for(vertrx ��ÿһ���ڽӵ�x){
    if(!Visit[x){//���û�б�������
        DFS(Graph,x,void(*Visit)(Vertex));
    }
   }
}
