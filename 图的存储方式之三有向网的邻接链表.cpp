#include <stdio.h>  
struct node{
	int u,v,w; 
}arr[500000];
void quickSort(int left,int right){
	if(left>right) return;//�������δ� 
	int i,j;//�����ڱ�  
	struct node temp;
	i=left;
	j=right; 
	temp=arr[left];//���յ�
	while(i<j){
	    //�ұߵ��ȶ�
	    while(arr[j].w>=temp.w&&i<j){//��һ���������жϱߵ�Ȩ�� ******д����if 
	    	if(arr[j].w==temp.w){//���Ȩ����Ⱦͼ����жϻ�β 
	    		if(arr[j].u>=temp.u){
	    			if(arr[j].u==temp.u){//��β��ͬ�ͼ����Ƚϻ�ͷ 
	    			    if(arr[j].v>=temp.v){//��ͷ���ڵ��ڣ�ȫ�����ڵ��ڣ���������Ѱ�� 
	    			    	j--; 	
						}else{//��ͷС����������� 
							break;
						}
					}else{//��β�󣬼��������ƶ� 
						j--; 
					}
				}else{//��βС����������� 
				    break;	
				}
			}else{//���Ȩ�ش�ͼ��������� 
				j--; 
			}
		}	
		arr[i]= arr[j];//�ݴ� 
		//��ߵ��ٶ�
		while(arr[i].w<=temp.w&&i<j){//д����if 
			if(arr[i].w==temp.w){//Ȩ����ͬ�ͼ����Ƚϻ�β
			    if(arr[i].u<=temp.u){
			    	if(arr[i].u==temp.u){//��β��ȾͱȽϻ�ͷ
					    if(arr[i].v<=temp.v){//��ͷС����������Ѱ��
						    i++; 	
						}else{//��ͷ�󣬾������� 
							break; 
						}
					}else{//��βС����������
					    i++; 
					}
				}else{//��β�󣬾������� 
					break; 
				}
			}else{//Ȩ��С����������Ѱ��
			    i++; 
			}	
		}
		 //�ҵ���ߵ������������ұ�
		 arr[j]=arr[i];	
	}
	//����׼�����м�
	arr[i]=temp; 
	//�ݹ����
	quickSort(left,i-1); 
	//�ݹ��ұ�	
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
			scanf("%d",&p);//��������ȡ��ַ 
			printf("%d %d\n",arr[p].u,arr[p].v);
		}	
	}	
}
