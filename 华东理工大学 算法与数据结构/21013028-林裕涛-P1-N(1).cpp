#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100
#define INFINITY 0
typedef int Vertex;
typedef int WeightType;
//typedef char DataType;

//图结点的定义
typedef struct GNode* PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];         //int G[][]创建邻接矩阵
	//DataType Data[MaxVertexNum];       //存顶点的数据
};

typedef PtrToGNode MGraph;   //定义为用邻接矩阵存储的图类型


//边的定义
typedef struct ENode* PtrToENode;
struct ENode {
	Vertex V1, V2;       //有向边
	WeightType Weight;   //权重
};
typedef PtrToENode Edge;

MGraph CreateGraph(int VertexNum)         //初始化一个有顶点但无边的图
{
	Vertex V, W;
	MGraph Graph;           //创建一个邻接矩阵存储的图类型Graph

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//初始化邻接矩阵
	//注：此处默认顶点编号从0开始
	for (V = 0; V < Graph->Nv; ++V)
	{
		for (W = 0; W < Graph->Nv; ++W)
			Graph->G[V][W] = INFINITY;
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	//插入边<V1,V2>
	Graph->G[E->V1][E->V2] = E->Weight;
	/*若为无向图，还要插入边<V2,V1>
	Graph->G[E->V2][E->V1] = E->Weight;*/
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d",&Nv);          //输入顶点个数
	Graph = CreateGraph(Nv);        //初始化有Nv个顶点但没有边的图
	//scanf("%d", &(Graph->Ne));
	if (1)        //如果有边
	{
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i < 10; i++) 
		{
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}

	for (int i = 0; i < Nv; i++)     //打印
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