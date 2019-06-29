#include<stdio.h>
#include<stdlib.h>
#define N 550000
typedef int ElemType;
struct node{
	ElemType data;
	struct node *next;
}*arr[N]; //创建用于标识所有弧尾的数组，其下标就是弧尾下标,从零开始 *********数组指针*******
int main() {
	int n,m,u,v,query,i;
	struct node *q,*p;//查询用 
	while(scanf("%d%d",&n,&m)!=EOF) {
	    //根据输入的节点的数目n初始化弧尾数组，即每一个节点暂时都没有出度 
	    for(i = 0; i < n; i++){
            arr[i] = NULL;
        }
	    //根据输入的有向边的条数m来创建有向图的邻接链表
		while(m--){
			scanf("%d%d",&u,&v);
			if(arr[u]==NULL){//如果数组尚未存储数据可以直接把弧头编号存放在数组数据域中 
			    arr[u] = (struct node *)malloc(sizeof(struct node));
                arr[u]->data = v;
                arr[u]->next = NULL;
			}else{//否则在弧尾的位置另辟空间存储弧头 
				p=(struct node*)malloc(sizeof(struct node));
				p->data=v;
				p->next=arr[u]->next; 
				arr[u]->next=p;	 
			}
		} 
		//输入询问的次数
		scanf("%d",&query);
		while(query--){
			scanf("%d%d",&u,&v);
			int flag=0;//弧头有无的标志 
			//查看是否存在有向边
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

