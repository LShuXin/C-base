#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char date;
    struct node*l,*r;
};

struct node*creat(int n,char a[],char b[])
{
    int i;
    struct node*t;
    if(n<=0)
        return NULL;
    t=(struct node*)malloc(sizeof(struct node));
    t->date=a[0];
    for(i=0;i<n;i++)
    {
        if(b[i]==a[0])
        {
            break;
        }
    }
    t->l=creat(i,a+1,b);
    t->r=creat(n-i-1,a+i+1,b+i+1);
    return t;
};

int high(struct node*p)
{
    if(p->l==NULL&&p->r==NULL){
    	return 1;
	}
    else
    {
        if(high(p->l)>high(p->r))
            return high(p->l)+1;
        else
            return high(p->r)+1;
    }
}

int main()
{
    int n;
    char a[55],b[55];
    while(~scanf("%d",&n))
    {
        scanf("%s %s",a,b);
        struct node*p=creat(n,a,b);
        int y=high(p);
        printf("%d\n",y);
    }
}
