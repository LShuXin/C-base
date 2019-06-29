   #include<stdio.h>  
    struct node  
    {  
        char data;  
        int l,r;  
    }t1[20],t2[20];  //创建二叉树结构体数组 
    int n,m;  //分别保存两个二叉树的节点数 
    void build(struct node *t,int mm)  
    {  //输入空二叉树，二叉树的节点数 
        int i;  
        for(i=0;i<mm;i++)  //根据二叉树输入的结点的个数创建二叉树  ，即为二叉树结构体数组赋值 
        {  
            //在使用scanf（%s）的时候遇到空格认为输入结束 
            char s[10];  // 用于保存一行中输入的三个字符 
            scanf("%s",s);  //读入字母 
            t[i].data=s[0];  //节点数据域赋值 
             scanf("%s",s);  //读入左子树编号 
             if(s[0]=='-') 
			 {
             	t[i].l=21; //指定一个比树的节点数大的索引 
			 } 
             else{
             	t[i].l=s[0]-'0';  //隐式数据类型转换 
			 } 
             scanf("%s",s);  //读入右子树编号 
             if(s[0]=='-')
			 {
             	t[i].r=21; 
			 }  
             else{
             	t[i].r=s[0]-'0';// //隐式数据类型转换 
			 }   
        }  
    }  
    int judge(int i,int j)  
    {  //两棵树完全一致或者互换后一致都是同构 
        if(t1[t1[i].l].data==t2[t2[j].l].data&&t1[t1[i].r].data==t2[t2[j].r].data) return 1;  
        if(t1[t1[i].l].data==t2[t2[j].r].data&&t1[t1[i].r].data==t2[t2[j].l].data) return 1;  
        return 0;  
    }  
    void ok()  
    {  
        int i,j;  
        int flag=0;  
        for(i=0;i<n;i++)  //在树一中遍历 
        {  
            for(j=0;j<m;j++)  //在树二中遍历 
            {  
                if(t1[i].data==t2[j].data)  //在树二中找到两颗二叉树中数据相同的节点，就是找到了同构后的 同一节点 ，然后比较同一节点的孩子 
                {  
                    if(judge(i,j)==0)  //如果发现不同构，立即退出在树二上的遍历 ，同时作树不同构的标记 
                    {  
                        flag=1;
						break;  
                    }else{//即使同构也要退出在树二上的遍历 ，因为 已经在树二中找到了与树一当前遍历位置上相同的的节点 ，只能说明到目前为止，树一当前遍历位置之前的都满足同构 ，树一继续遍历 
					    break; 
					} 
                }  
            } 
			 
            if(j==m)  //当j=m-1时遍历到 树二的末尾，如果 j=m，则说明，从未进入judge，说明树二中不存在树一对应位置的元素 
            {  
                flag=1;
				break;  
            }  
        }  
        if(flag) 
		{
			printf("No\n"); 	
		}
        else
		{
		    printf("Yes\n"); 
		}  
    }  
    int main()  
    {  
        while(~scanf("%d",&n))  
        {  
            build(t1,n);  
      
            scanf("%d",&m);  
            build(t2,m);  
      
            ok();  
        }  
        return 0;  
    }  



