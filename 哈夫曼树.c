#include<stdio.h>
//�ڹ����������֮ǰ�����е�Ԫ���Ѿ������˶��У��ڽ��й�������������֮ǰ��Ҫ����ת��Ϊ��С��
typedef struct HTnode HuffmanTree;
typedef struct HTnode{//������������Ľڵ�ṹ
    int weight;
    HuffmanTree Lchild;
    HuffmanTree Rchild;
}
HuffmanTree Huffman(Heap H){
 int i,n;
 HuildHeap(H);// //����ת��Ϊ��С��
 HuffmanTree T;//����һ�Ź�������
 n=--H->size;//Ҫ����С�ѽ���size-1�ι������ϲ�
 for(;i>0;i--){
    T=(HuffmanTree)malloc(sizeof(HTnode));
    T->Lchild=DeleteMin(H);
    T->Rchidl=DeleteMin(H);//ִ��һ�κϲ�
    T->weight=T->Lchild->weight+T->Rchild->weight;
    Insert(H,T);//������׷�ӵ���С��
 }
 return DeleteMin(H);//���ʣ�µ��Ǹ�����ָ�����չ��������ĸ�ָ��
}





