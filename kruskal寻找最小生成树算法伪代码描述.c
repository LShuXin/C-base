int KrusKal(LGraph Graph,LGraph MST)
{
    /*将最小生成树保存到MST中并且返回最小权重和*/
    MST=保存了原图所有的顶点但不保存边的图；
        while(MST中含有的边数不到Graph-Nv-1&&原图中的边集E非空)
    {
        从E中找出最小代价边(v,w);
        从E中删除此边(v,w);
        if((v,w)不在MST中构成回路)
        {
            将(v,w)加入MST;
        }
        else
        {
            E中永久的删除(v,w);
        }
    }
    if(MST中收集的边数不足Graph->Nv-)
    {
        return ERROR;
    }
    else
    {
        return ERROR;
    }
}
