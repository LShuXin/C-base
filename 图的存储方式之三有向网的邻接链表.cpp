#include <stdio.h>  
struct node{
	int u,v,w; 
}arr[500000];
void quickSort(int left,int right){
	if(left>right) return;//出过两次错 
	int i,j;//左右哨兵  
	struct node temp;
	i=left;
	j=right; 
	temp=arr[left];//参照点
	while(i<j){
	    //右边的先动
	    while(arr[j].w>=temp.w&&i<j){//第一级，首先判断边的权重 ******写成了if 
	    	if(arr[j].w==temp.w){//如果权重相等就继续判断弧尾 
	    		if(arr[j].u>=temp.u){
	    			if(arr[j].u==temp.u){//弧尾相同就继续比较弧头 
	    			    if(arr[j].v>=temp.v){//弧头大于等于，全部大于等于，继续向左寻找 
	    			    	j--; 	
						}else{//弧头小，就是这个了 
							break;
						}
					}else{//弧尾大，继续向左移动 
						j--; 
					}
				}else{//弧尾小，就是这个了 
				    break;	
				}
			}else{//如果权重大就继续向左走 
				j--; 
			}
		}	
		arr[i]= arr[j];//暂存 
		//左边的再动
		while(arr[i].w<=temp.w&&i<j){//写成了if 
			if(arr[i].w==temp.w){//权重相同就继续比较弧尾
			    if(arr[i].u<=temp.u){
			    	if(arr[i].u==temp.u){//弧尾相等就比较弧头
					    if(arr[i].v<=temp.v){//弧头小，继续向右寻找
						    i++; 	
						}else{//弧头大，就是他了 
							break; 
						}
					}else{//弧尾小，继续向右
					    i++; 
					}
				}else{//弧尾大，就是他了 
					break; 
				}
			}else{//权重小，继续向右寻找
			    i++; 
			}	
		}
		 //找到左边的数，交换到右边
		 arr[j]=arr[i];	
	}
	//将基准数放中间
	arr[i]=temp; 
	//递归左边
	quickSort(left,i-1); 
	//递归右边	
	quickSort(i+1,right);
}
int main(){
	int n,m,i,query,p;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=0;i<m;i++){
			scanf("%d %d %d",&arr[i].u,&arr[i].v,&arr[i].w);
		}
		quickSort(0,m-1);
		scanf("%d",&query);
		for(i=0;i<query;i++){
			scanf("%d",&p);//出错，忘记取地址 
			printf("%d %d\n",arr[p].u,arr[p].v);
		}	
	}	
}
