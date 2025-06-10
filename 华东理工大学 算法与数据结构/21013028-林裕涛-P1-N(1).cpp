#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100
#define INFINITY 0
typedef int Vertex;
typedef int WeightType;
//typedef char DataType;

//ͼ���Ķ���
typedef struct GNode* PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];         //int G[][]�����ڽӾ���
	//DataType Data[MaxVertexNum];       //�涥�������
};

typedef PtrToGNode MGraph;   //����Ϊ���ڽӾ���洢��ͼ����


//�ߵĶ���
typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2;       //�����
	WeightType Weight;   //Ȩ��
};
typedef PtrToENode Edge;

MGraph CreateGraph(int VertexNum)         //��ʼ��һ���ж��㵫�ޱߵ�ͼ
{
	Vertex V, W;
	MGraph Graph;           //����һ���ڽӾ���洢��ͼ����Graph

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//��ʼ���ڽӾ���
	//ע���˴�Ĭ�϶����Ŵ�0��ʼ
	for (V = 0; V < Graph->Nv; ++V)
	{
		for (W = 0; W < Graph->Nv; ++W)
			Graph->G[V][W] = INFINITY;
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	//�����<V1,V2>
	Graph->G[E->V1][E->V2] = E->Weight;
	/*��Ϊ����ͼ����Ҫ�����<V2,V1>
	Graph->G[E->V2][E->V1] = E->Weight;*/
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d",&Nv);          //���붥�����
	Graph = CreateGraph(Nv);        //��ʼ����Nv�����㵫û�бߵ�ͼ
	//scanf("%d", &(Graph->Ne));
	if (1)        //����б�
	{
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i < 10; i++) 
		{
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}

	for (int i = 0; i < Nv; i++)     //��ӡ
	{
		for (int j = 0; j < Nv; j++)
		{
			printf("%d ", Graph->G[i][j]);
		}
		printf("\n");
	}
	return Graph;
}


int main()
{
	BuildGraph();
	return 0;
}