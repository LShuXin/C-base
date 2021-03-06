#include<stdio.h>
int arr[100];
void quickSort(int left,int right){
	int i,j,t,temp;
	if(left>right) return;
	temp=arr[left];//保存基准数
	i=left;
	j=right;
	while(i!=j){//从数列的最右边寻找小于基准数的，从数列左半部分寻找比基准数大的进行交换，右边先开始移动
	    while(arr[j]>=temp&&i<j){//出过错 
	    	j--;
		}
		while(arr[i]<=temp&&i<j){//出过错 
			i++;
		}
		if(i<j){
			t=arr[i];//交换 
		    arr[i]=arr[j];
		    arr[j]=t;	
		}
	}
	//交换完毕将基准数放到数列的中间
	arr[left]=arr[i];//出过错 
	arr[i]=temp;
	//递归处理左半部分数列
	quickSort(left,i-1); 
	//递归处理右半部分数列 
	quickSort(i+1,right);	
}
//以下是测试、
int main(){
	int p;
	for(p=0;p<10;p++){
		printf("请输入第%d个数\n",p); 
		scanf("%d",&arr[p]);
	}
	quickSort(0,9);
	for(p=0;p<10;p++){
		printf("%d",arr[p]);
	}
} 
