#include <stdio.h>
#include <stdlib.h> 
int main(){
	int i,n,*pa;
	scanf("%d",&n);
	pa=(int*)malloc(n*sizeof(int));//���ɶ�̬����
	for(i=0;i<n;i++){
		*(pa+i)=i*i;
	} 
	for(i=0;i<n;i++){
		printf("%d",*(pa+i));
	}
	for(i=0;i<n;i++){
		scanf("%d",&pa[i]);
	}
	for(i=0;i<n;i++){
		printf("%d",pa[i]);
	}
	free(pa);//�ͷ�����ռ� 
} 
