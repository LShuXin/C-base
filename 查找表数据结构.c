#define maxsize 100
typedef int KeyType;
typedef struct node{//记录解构,查找表的元素
    KeyType key;//主键
    char name[20];//其他记录字段
    char sex[10];
    int age;
}ElemType;
//查找表结构
typedef struct{
  ElemType Elem[maxszie];
  int length;
}SSTable;
SSTable s1,SSTable s2;

