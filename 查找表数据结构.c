#define maxsize 100
typedef int KeyType;
typedef struct node{//��¼�⹹,���ұ��Ԫ��
    KeyType key;//����
    char name[20];//������¼�ֶ�
    char sex[10];
    int age;
}ElemType;
//���ұ�ṹ
typedef struct{
  ElemType Elem[maxszie];
  int length;
}SSTable;
SSTable s1,SSTable s2;

