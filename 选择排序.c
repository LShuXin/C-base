void SelectSort(RecType r[],int N){
    //思路:每一次循环从后面的无序的记录中选择关键字最小的记录放到有序序列的末尾
 int i,j,min;
 RecType x;//错误！！！
 for(i=1;i<N;i++){
    min=i;
    for(j=i+1;j<=N;j++){
        if(r[j].key<r[min].key)
                min=j;
    }
    if(min!=i){
        x=r[i];//！！
        r[i]=r[min];//！！
        r[min]=x;//！！！
    }
 }
}
//算法分析：
//1.最好的情况：
//      比较（任何情况）：i=1 n-1次    i=2 n-2次   i=n-1 1次   O(n2)
//      交换：不交换                                             0
//2.最坏的情况：
//      比较（任何情况）：i=1 n-1次    i=2 n-2次   i=n-1 1次   O(n2)
//      交换：              n-1 次 每次都交换一次(3)           O(3(n-1))
