#include<stdio.h>
#include<stdlib.h>
//ʹ���ڽ�����洢
//ʹ������ᳬʱ
struct node{
	int data;
	struct node *next;
}*a[5000];
//������±������ÿһ�����
int main(){
	int i,j,m,n,query,flag;
	struct node*p; 
	while(~scanf("%d",&n)){//���ĸ��� 
	       //��ʼ����ͷ���� 
		    for(i=0;i<n;i++){
		    	a[i]=NULL;
			}
			//����������� 
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					scanf("%d",&m); 
					//ֻ�о�������Ϊ�Ž��д������򲻽��д�������Ϊnull
					if(m==1){
						if(a[i]==NULL) {//������鱾��û�д洢ָ��Ļ�ͷ����ֱ�Ӵ�������
							p=(struct node*)malloc(sizeof(struct node));
							p->data=1;//z=ָ���Ա����ʹ�ü�ͷ**����� 
							p->next=NULL;
							a[i]=p;
						}else{	//���������ռ䣬�����ڽ����� 
						    p=(struct node*)malloc(sizeof(struct node));
							p->data=j;//����һ����j���ǻ�ͷ*****������	 
							p->next=a[i]->next;
							a[i]->next=p; 
						}	
					} 	
				}
		   }
		   scanf("%d",&query); //�����ѯ����
		   for(i=0;i<query;i++){
		   	    scanf("%d%d",&m,&n);
		   	    flag=0;
		   	    if(a[i]==NULL){//������ָ����1��ͷ 
		   	    	flag=0;
				}else{
				   	p=a[i];//***************������ȡ�˵�ַ 
				   	while(p){
				   	   if(p->data==n){
				   	   	    flag=1;
				   	   	    break;
						}else{
							p=p->next;
						}	
					}
				}
				if(flag==0){
					printf("No\n");
				}else{
					printf("Yes\n");
				}
		   } 			
	}

} 

