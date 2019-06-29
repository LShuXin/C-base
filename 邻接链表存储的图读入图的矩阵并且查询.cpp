#include<stdio.h>
#include<stdlib.h>
//使用邻接链表存储
//使用数组会超时
struct node{
	int data;
	struct node *next;
}*a[5000];
//数组的下标代表了每一个结点
int main(){
	int i,j,m,n,query,flag;
	struct node*p; 
	while(~scanf("%d",&n)){
	       //结点的个数 
	       //初始化表头数组 
		    for(i=0;i<n;i++){
		    	a[i]=NULL;
			}
			//读入图矩阵 
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					scanf("%d",&m); 
					//只有矩阵数据为才进行处理，否则不进行处理，让其为null
					if(m==1){
						if(a[i]==NULL) {
						    //表头数组为空 
							p=(struct node*)malloc(sizeof(struct node));
							p->data=1;//z=指针成员访问使用箭头**出错过 
							p->next=NULL;
							a[i]=p;
						}else{
						    p=(struct node*)malloc(sizeof(struct node));
							p->data=j;//不是一而是j，是弧头*****出过错	 
							p->next=a[i]->next;
							a[i]->next=p; 
						}	
					} 	
				}
		   }
		   scanf("%d",&query); //读入查询次数
		   for(i=0;i<query;i++){
		   	    scanf("%d%d",&m,&n);
		   	    flag=0;
		   	    if(a[m]==NULL){//不存在指定的1弧头 ************************出错，m写成了i 
		   	    	flag=0;
				}else{
				   	p=a[m];//***************出过错，取了地址  出错，m写成了i 
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
    return 0; 
} 

