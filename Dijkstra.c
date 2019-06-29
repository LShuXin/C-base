#include<stdio.h> 
#include <stdlib.h>
//��Դ���·��
#define true 1
#define false 0
#define INFINITY 65535
#define ERROR 0
#define MaxVertexNum 100
typedef int DataType;
typedef int Vertex;
typedef int bool;
typedef int WeightType;
typedef struct GNode *PtrToGNode;
typedef struct GNode {
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum];
	int Nv,Ne;
};
typedef PtrToGNode MGraph;
Vertex FindMinDist(MGraph Graph,WeightType Dist[],bool collected[]) {
	Vertex v,MinV;
	WeightType MinDist=INFINITY;
	for(v=0; v<Graph->Nv; v++) {
		if(collected[v]==false && Dist[v]<MinDist) { //û�б���¼������ȥȨֵ��С
			MinDist=Dist[v];
			MinV=v;
		}
	}
	if(MinDist<INFINITY) {
		return MinV;
	} else {
		return ERROR;
	}
}

bool Dijkstra(MGraph Graph,WeightType dist[], bool collected[],/*��Դ���·���е�Դ*/ Vertex s,Vertex path[]){
	Vertex v,w;//��ʼ��·���������ռ�����
	for(v=0; v<Graph->Nv; v++) {
		dist[v]=Graph->G[s][v];
		collected[v]=false;
		path[v]=-1;
	}
	collected[s]=true;//Դ���ռ�
	dist[s]=0;//Դ���ռ�
	while(1) {
		v=FindMinDist(Graph,dist,collected);
		if(!v) {
			break;
		}
		collected[v]=true;
		for(w=0; w<Graph->Nv; w++) {
			if(collected[w]==false&&Graph->G[v][w]<INFINITY) {
				if(Graph->G[v][w]<0)//����dist[W]<0
					return false;
				if(dist[w]>dist[v]+Graph->G[v][w]) {
					dist[w]=dist[v]+Graph->G[v][w];
					path[w]=v;
				}
			}
		}
	}
	return true;
}

int main() {
	int vertexnum,v,w,res,s;
	Vertex path[MaxVertexNum];
	WeightType Dist[MaxVertexNum];
	bool collected[MaxVertexNum];
	MGraph Graph;
	Graph=(PtrToGNode)malloc(sizeof(struct GNode));
	for(v=0;v<MaxVertexNum;v++){
		collected[v]=false;
	}
	printf("*********************************������ͼ�Ķ������********************************\n");
	scanf("%d",&vertexnum);
	Graph->Nv=vertexnum; 
	printf("*********************************������ͼ���ڽӾ���********************************\n");
	for(v=0; v<vertexnum; v++) {
		for(w=0; w<vertexnum; w++) {
			scanf("%d",&(Graph->G[v][w]));
		}
	}
	printf("**************************************������Դ*************************************\n");
	scanf("%d",&s);
	res=Dijkstra(Graph,Dist,collected,s,path);
	if(res==1)
		printf("OK");
	else
		printf("ERROR");
		return 0;
	}
