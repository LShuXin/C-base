#define true 1
#define false 0
typedef int bool;
bool TopSort(MGraph Graph,Vertex TopOrder[]){
    //��ͼGraph����������������֮��Ķ������б�����TopOrder�У��������ʧ�ܣ�����false ���򷵻�true
    /*��ͼGraph���б�������ÿ���������ȱ�����InDgree[]��*/
    for(cnt=0;cnt<Graph->Nv;cnt++){
        v=ͼ�����Ϊ0�Ķ��㣻
        if(�����������ĵ�v){
            prinf("ͼ�д��ڻ�");
            break;
        }
        TopOrder[cnt]=v;
        for(v��ÿһ���ڽӵ�w){
            InDgree[w]--;
            wɾ����v�ıߣ�
        }
    }
    if(cnt!=Graph->Nv){
        printf("ͼ�д��ڻ�");
        return false;
    }
    return true;
}
