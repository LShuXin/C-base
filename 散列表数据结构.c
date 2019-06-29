#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 //定义散列表的长度为数组长度
#define NULLKEY -32767
typedef struct
{
    int *elem;//数据元素存储基地址，动态分配数组
    int count;//当前数据元素的个数
} HashTabe;
int m=0;//全局变量，散列表的长度
//初始化散列表
Status InitHashTable(HashTabe *H)
{
    int i;
    m=HASHSIZE;
    H->count=m;//忘记写
    H->elem=(int*)mallod(m*sizeof(int));
    for(i=0; i<m; i++)
        H->elem[i]=NULLKEY;
    return OK;
}
//定义散列函数，多个
int Hash(int key)
{
    return key%m;//除留余数散列函数
}
//关键字插入散列表的函数（线性探测）
void InsertHash(HashTabe *H,int key)
{
    int addr=Hash(key);
    while(H->elem(addr)!=NULLKEY)
    {
        addr=(addr+1)%m;//线性探测
    }
    H->elem[addr]=key;
}
Status HashSearch(HashTable H,int key,int *addr)
{
    *addr=Hash(key);
    while(H->elem[*addr]!=NULLKEY)
    {
        *addr=(*addr+1)%m;
        if(H->elem[*addr]==NULLKEY||(*addr)=Hash(key))
            return UNSUCCESS;
    }
    return SUCCESS;
}
