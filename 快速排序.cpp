#include<stdio.h>
int arr[100];
void quickSort(int left,int right){
	int i,j,t,temp;
	if(left>right) return;
	temp=arr[left];//�����׼��
	i=left;
	j=right;
	while(i!=j){//�����е����ұ�Ѱ��С�ڻ�׼���ģ���������벿��Ѱ�ұȻ�׼����Ľ��н������ұ��ȿ�ʼ�ƶ�
	    while(arr[j]>=temp&&i<j){//������ 
	    	j--;
		}
		while(arr[i]<=temp&&i<j){//������ 
			i++;
		}
		if(i<j){
			t=arr[i];//���� 
		    arr[i]=arr[j];
		    arr[j]=t;	
		}
	}
	//������Ͻ���׼���ŵ����е��м�
	arr[left]=arr[i];//������ 
	arr[i]=temp;
	//�ݹ鴦����벿������
	quickSort(left,i-1); 
	//�ݹ鴦���Ұ벿������ 
	quickSort(i+1,right);	
}
//�����ǲ��ԡ�
int main(){
	int p;
	for(p=0;p<10;p++){
		printf("�������%d����\n",p); 
		scanf("%d",&arr[p]);
	}
	quickSort(0,9);
	for(p=0;p<10;p++){
		printf("%d",arr[p]);
	}
} 
