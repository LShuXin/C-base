#include <stdio.h>
typedef int ElemType
/*栈的链表实现*/
//定义节点结构
typedef struct node{
    ElemType data;
    struct node *next;
}node *Top;
//进栈函数
struct node *LStackPush(struct node *top,ElemType e){
    struct node *p;//创建指向结构体节点的指针
    p=(struct node*)malloc(sizeof(struct node));//根据结构体的大小分配内存空间
    p->data=e;//将数据写入
    p-next=top;//将栈顶节点加在链栈上
    top=p;//这是新的站顶指针，注意栈顶指针现在是直接指向栈顶元素的
    return top;//返回栈顶指针
}
//退站函数
struct node *LinkStackPop(struct node *top){
    //传入的是一个栈顶指针，返回的是一个删除了栈顶元素之后的指向新的栈顶的指针
    if(top==NULL){
        exit(EXIT_FAILURE);//如果传入的是一个空指针，则说明栈已空，错误退出
    }else{
        top=top->next;//将top指向栈顶元素的下一个元素
        reurn top;//返回去掉栈顶元素之后的新的栈顶元素的指针
    } 
}

bool isValid(char* s) {
    
    
}
