#define MAXN 1000
typedef int ElemType;//Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ
typedef int SetName;//Ĭ���ø��ڵ���±���Ϊ��������
typedef ElemType SetType[MAXN];
//����Ԫ�����ڵļ���
SetName Find(/*һ����������*/SetType s,/*һ���Ǹ���������ʶһ��Ԫ�ظ���*/ElemType x)
{
//s[x]��ֵ������x�ĸ�Ԫ�أ�����Ǹ�����
    for(; s[x]>=0; x=s[x])
//��s[x]��Ϊ��ʱ��˵�����±�ֵ����ʶ��һ������(��������)
        return x;
}
//���ϵĲ�����
void Union(SetType s,SetName root1,SetName root2){
//root1,��root2 ��Ϊ�Ǹ����������Դ�����һ������
//��ʵ����������±꣬�������±�����-1���±��Ψһ�������˼���
s[root2]=root1;//�����Ͳ�����root2������ϣ���ʣ��root1��һ����
//�ϲ�ʱֻ��Ҫ��һ�����ϵļ��ϱ�ʶ�е�-1 �滻Ϊ��һ�����ϵĸ���ʶ�±���
}

