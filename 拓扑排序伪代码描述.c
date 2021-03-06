#define true 1
#define false 0
typedef int bool;
bool TopSort(MGraph Graph,Vertex TopOrder[]){
    //对图Graph进行拓扑排序，排序之后的顶点序列保存在TopOrder中，如果排序失败，返回false 否则返回true
    /*对图Graph进行遍历，将每个顶点的入度保存在InDgree[]中*/
    for(cnt=0;cnt<Graph->Nv;cnt++){
        v=图中入度为0的顶点；
        if(不存在这样的点v){
            prinf("图中存在环");
            break;
        }
        TopOrder[cnt]=v;
        for(v的每一个邻接点w){
            InDgree[w]--;
            w删掉与v的边；
        }
    }
    if(cnt!=Graph->Nv){
        printf("图中存在环");
        return false;
    }
    return true;
}
