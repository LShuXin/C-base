#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *left,*right;
};
struct node *creat(int n,char *str1,char *str2)//���������ؽ�������������
{
    struct node *root;
    int i;
    if(n==0)
        return NULL;
    root=(struct node *)malloc(sizeof(struct node));
    root->data=str1[0];//�ҵ����ڵ㣬���ڵ�Ϊstr1���������У��ĵ�һ��
    for(i=0;i<n;i++)//�ҵ�str2���������У��ĸ��ڵ��λ��
    {
        if(str2[i]==str1[0])
            break;
    }
    root->left=creat(i,str1+1,str2);//���������ĳ��ȣ���������str1�п�ʼλ�õĵ�ַ����������str2�п�ʼλ�õĵ�ַ��
    root->right=creat(n-i-1,str1+i+1,str2+i+1);//���������ĳ��ȣ���������str1�п�ʼλ�õĵ�ַ����������str2�п�ʼλ�õĵ�ַ��
    printf("%c",root->data);//����������
    return root;
};
int main()
{
    int n;
    char str1[1100],str2[1100];
    scanf("%s",str1);
    scanf("%s",str2);
    n=strlen(str1);
    creat(n,str1,str2);
    printf("\n");
    return 0;
}
