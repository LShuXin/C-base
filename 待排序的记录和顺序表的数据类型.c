#define MAXSIZE 100
typedef int KeyType;//һ����¼��������
typedef int InfoType;//��¼�е�������Ϣ
//��¼����
typedef struct{
    KetType key;
    InfoType otherinfo��
}RecType;
//˳�������
typedef struct{
    RecType r[MAXSIZE+1];//�����ڱ�
    int length;//˳���ĳ���
}SeqList;
