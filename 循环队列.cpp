//���е�˳��洢��ѭ�����У�
#include<stdio.h>
#define MAXLENG 10
#define OK 1
#define ERROR -1
#define OVERFLOW -2
typedef int ElemType;
//����˳����еĽṹ
typedef struct{
	ElemType elem[MAXLENG];
	int rear,front;//���е�ͷ��ָ�롱��β��ָ�롱 
	//ͷָ��ֱ��ָ���ͷԪ��
	//βָ��ָ���βԪ�صĺ�һ��λ�ã��Ա�ʶ������ջ��
    //����������(rear+1)%maxleng=front
    //���пյ����� front ==rear	
}SeQueue;

//ѭ�����еĳ�ʼ���㷨
SeQueue InitQueue(){
	SeQueue s;
	s.front=s.rear=0; 
	return s;
} 
//ѭ�����еĽ����㷨
int InQueue(SeQueue &Q,ElemType e){
	//����������������
    //��һ��������һ�����б�����
    //�ڶ���������Ҫ�����Ԫ�� 
    //���ؽ��ӳɹ����
	if((Q.rear+1)%MAXLENG==Q.front){
	    printf("����������\n");
		return 	OVERFLOW; 
	}else{
		//��Ϊ������βָ���ָ���˶�βԪ�صĺ�һλ��
		//������ʱ�����ڶ�βָ���λ�� ����Ԫ�أ��ٰѶ�βָ������ƶ�һ��λ�� 
		Q.elem[Q.rear++]=e;
		printf("%d �Ѿ����\n",e);
		return OK;
	}
}
//ѭ�����г����㷨
int DeQueue(SeQueue &Q,ElemType *e){//�����Ĳ�������*******ûдȡ��ַ���ų��� 
	//ѭ�����еĳ����㷨������������
	//��һ��������Ҫ���ӵĶ��е�����
	//�ڶ������������ڱ������Ԫ�ص�ָ��
	//���е����ò�ȡ��������
	if(Q.rear==Q.front){ 
		printf("�����ѿգ��޷����ӣ�");
		return OVERFLOW; 	
    }else{//ֱ�ӽ���ͷָ���һ 
        printf("���ӵ�ͷָ���ǣ�%d",Q.front);
        (*e)=Q.elem[Q.front];
        Q.front=(Q.front+1)%MAXLENG;////******************ֱ�Ӽ�һ���� 
        printf("���Ӻ��ͷָ���ǣ�%d",Q.front);
		return OK; 
    }
}
int main(){
	int i,e;
	SeQueue s1=InitQueue();
	//���� 
	for(i=1;i<12;i++){
		InQueue(s1,i*i);
	}
	//����
    for(i=0;i<12;i++){
		DeQueue(s1,&e);
		printf("   %d�Ѿ�����\n",e);
	}
	return 0;
}
