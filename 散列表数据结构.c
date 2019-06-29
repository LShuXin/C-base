#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 //����ɢ�б�ĳ���Ϊ���鳤��
#define NULLKEY -32767
typedef struct
{
    int *elem;//����Ԫ�ش洢����ַ����̬��������
    int count;//��ǰ����Ԫ�صĸ���
} HashTabe;
int m=0;//ȫ�ֱ�����ɢ�б�ĳ���
//��ʼ��ɢ�б�
Status InitHashTable(HashTabe *H)
{
    int i;
    m=HASHSIZE;
    H->count=m;//����д
    H->elem=(int*)mallod(m*sizeof(int));
    for(i=0; i<m; i++)
        H->elem[i]=NULLKEY;
    return OK;
}
//����ɢ�к��������
int Hash(int key)
{
    return key%m;//��������ɢ�к���
}
//�ؼ��ֲ���ɢ�б�ĺ���������̽�⣩
void InsertHash(HashTabe *H,int key)
{
    int addr=Hash(key);
    while(H->elem(addr)!=NULLKEY)
    {
        addr=(addr+1)%m;//����̽��
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
