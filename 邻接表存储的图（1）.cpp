#include<stdio.h>
#include<stdlib.h>
#define N 550000
typedef int ElemType;
struct node{
	ElemType data;
	struct node *next;
}*arr[N]; //�������ڱ�ʶ���л�β�����飬���±���ǻ�β�±�,���㿪ʼ *********����ָ��*******
int main() {
	int n,m,u,v,query,i;
	struct node *q,*p;//��ѯ�� 
	while(scanf("%d%d",&n,&m)!=EOF) {
	    //��������Ľڵ����Ŀn��ʼ����β���飬��ÿһ���ڵ���ʱ��û�г��� 
	    for(i = 0; i < n; i++){
            arr[i] = NULL;
        }
	    //�������������ߵ�����m����������ͼ���ڽ�����
		while(m--){
			scanf("%d%d",&u,&v);
			if(arr[u]==NULL){//���������δ�洢���ݿ���ֱ�Ӱѻ�ͷ��Ŵ���������������� 
			    arr[u] = (struct node *)malloc(sizeof(struct node));
                arr[u]->data = v;
                arr[u]->next = NULL;
			}else{//�����ڻ�β��λ����ٿռ�洢��ͷ 
				p=(struct node*)malloc(sizeof(struct node));
				p->data=v;
				p->next=arr[u]->next; 
				arr[u]->next=p;	 
			}
		} 
		//����ѯ�ʵĴ���
		scanf("%d",&query);
		while(query--){
			scanf("%d%d",&u,&v);
			int flag=0;//��ͷ���޵ı�־ 
			//�鿴�Ƿ���������
			if(arr[u]==NULL){
		      flag=0;	
			} else{
			    q=arr[u];
			    while(q){
					if(q->data==v){
						flag=1;
						break;
					}
					q=q->next;
				} 
		    }
			
		
			if(flag){
				printf("Yes\n");
		    } else{
				printf("No\n");
	    	}	
	}
 }
}

