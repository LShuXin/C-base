#include<stdio.h>
struct node{
	int data;
	struct *next;
}arr[550000];
int main() {
	int n,m,i,u,v;
	while(scanf("%d %d",&n,&m)!=EOF){
		while(n--){
		  arr[n]=NULL;	
		}
		while(m--){
			scanf("%d %d",&u,&v);
			if(arr[u]==NULL){
				arr[u].data=v;
				arr[u].next=NULL; 
			}
			else{
			    struct node*p=( struct node *)malloc(struct node);
			    p->data=v;
			    arr[u].next=p;
			}	
		}
		
	}	
}

