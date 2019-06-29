#include<stdio.h>
#include<stdlib.h> 
#define LENG 100
#define OVERFLOW -2
#define ERROR 0
#define OK 1
//�򵥵Ĵ���ͷ���Ķ���
//��Ҫ�����������͵Ľڵ㣺��һ�ִ������Ԫ���Լ�ָ����һ��Ԫ�ؽڵ��ָ��
//�ڶ��ֽڵ����붨��һ��ͷ��㣺ͷ���������ָ��ָ����ָ�����;�������Ľڵ����ͣ����ڷֱ�ָ����еĶ�ͷ�ڵ����β�ڵ� 
typedef int ElemType; 
typedef struct node{//���û��typedef ���ܶ������ 
	ElemType data;
	struct node *next;
}Qnode,*QueuePtr;
//Qnode Ԫ�ؽڵ�����
//Queueptr ָ��Ԫ�ؽڵ����͵�ָ�� 
typedef struct{
	Qnode *front;
	Qnode *rear;
}LinkQueue; 
//linkQueue ����ͷ�������
//��ʼ�������㷨

LinkQueue InitQueue(){
	//��ʼ�����У���һ����ͷ�ڵ�
	//ͷ����ָ����Ϊ��
	LinkQueue Q;//LinkQueue Ϊͷ������� �����������ڵ��Ա//QueuePtr Ϊָ��ڵ��ָ������//Qnode Ϊ�ڵ�����
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(Qnode));//����������������Ǳ�ͷ�ڵ� 
	Q.front->next==NULL;//��ͷ����ָ����Ϊ�� 
	return Q;
}
//����ͷ���Ķ��в�����Ԫ�ص��㷨
LinkQueue Insert1(LinkQueue Q,ElemType e){
	//���еĲ����㷨һ
	//����Ĳ�����һ�����е�ͷ���
	//�������ͷ��Ӧ�Ķ��еĺ������Ԫ�غ��ٷ��������ͷ
	Qnode *p;
	p=(QueuePtr)malloc(sizeof(Qnode));//QueuePtr ��ָ��Ԫ�ؽڵ��ָ������ Qnode ��Ԫ�ؽڵ�����
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;//������ȥ
	Q.rear=p;
	return Q;	
}
//����ͷ���Ķ��еĲ����㷨
int Insert2(LinkQueue *Q,ElemType e){
	//����Ĳ�����ָ���ͷ��ָ�룬����ֵ�������Ƿ�ɹ�����Ԫ��
	//�����˶�̬�����ڴ�ʧ��
	Qnode *p;
	p=(QueuePtr)malloc(sizeof(Qnode));//QueuePtr Ϊָ��Ԫ�ؽڵ��ָ������ QnodeΪԪ�ؽڵ�����
	if(!p){
	    printf("OVERFLOW!");
	    return ERROR;
	}
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return OK;	
}

LinkQueue Delete(LinkQueue Q,ElemType *e){
	if(Q.front==Q.rear){//��ָ����ͷ��㣨���Ƕ�ͷ�ڵ㣩 �������Ѿ�Ϊ����
	    printf("�����ѿգ��޷����ӣ�");
		return Q;
	}
	//������ ��ɾ���㷨 ����һ�����б�������һ������Ԫ�����͵�ָ��
	//����ֵΪ���Ӻ�Ķ���
	//��������Ԫ��ָ����Ϊ������Ŀ�����ڳ��ӵ�ͬʱ���Ƚ�ɾ��������Ԫ��copyһ�ݵ���һ������
	QueuePtr p;//��Ҫ�õ�һ��ָ���ͷ��������ͷ��㣩��ָ�������ָ���ת��
	p=Q.front->next;//pָ���˶�ͷ�ڵ������ͷ��� 
	(*e)=p->data; 
	Q.front->next=p->next;//ͷ��㣨���Ƕ�ͷ�ڵ㣩ָ���µĶ�ͷ�ڵ� 
	//���ֻ��һ����ͷ�ڵ�,��ô���Ӻ�Ӧ����rearָ��ͷ��㣨���Ƕ�ͷ��
	if(Q.rear==p){//!!!!!!!!!!!!!!!!!!!!!
		Q.rear=Q.front; //�ٴ�ͬʱָ���ͷ�ڵ� 
	} 
	free(p);
	return Q; 	
} 
int main(){
	int flag=0;//������ɵı�־ 
	int e,i;
	//��ʼ��һ������
	LinkQueue linkqueue;
	linkqueue=InitQueue(); 
	//�����������Ԫ��
	for(i=1;i<10;i++){
		Insert2(&linkqueue,i*i);
	}
	for(i=1;i<10;i++){
		Delete(linkqueue,&e);
		printf("%d\n",e);
	} 
	//�������Ԫ�� 
	return 0;
} 



















