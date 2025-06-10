#include<bits/stdc++.h>


#define Vextype  char
#define   Edgetype   int
#define MaxVerNum  30           /* 最大顶点个数 */

typedef  struct ArcNode			/*边结点*/
{
	int adjvex;					/*该边所指向的顶点的位置*/
	struct ArcNode * nextarc;	/*指向下一条边的指针*/
}ArcNode;						
typedef struct VNode
{
	Vextype data;				/*顶点信息*/
	ArcNode * firstarc;			/*指向第一条依附该顶点的边的指针*/
}VNode, AdjList[MaxVerNum];		/*AdjList表示邻接表类型*/
typedef struct 
{
	AdjList vertices;			/*邻接表*/
	int vexnum, arcnum;			/*图的当前顶点数和边数*/
}ALGraph,*PALGraph;

void CreateUDG(ALGraph *G)	/*采用邻接表表示法，创建无向图G*/
{
	int i,j,k;
	ArcNode *pe;
	printf("输入顶点数和边数:");
	scanf("%d%d", &(G->vexnum), &(G->arcnum));/* 输入顶点数和边数 */
	getchar();
	printf("输入顶点信息:\n");
	for (i = 0; i < G->vexnum; i++)				/*输入各点，构造表头结点表*/
	{
		printf(" V%d=", i);
		scanf("%c", &(G->vertices[i].data)); /* 输入顶点信息，建立顶点表 */
		getchar();
		G->vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G->arcnum; k++)			/*输入各边，构造邻接表*/
	{
		printf("输入边(vi,vj)的顶点序号i%d,j%d（空格分隔）:",i,j);
		scanf("%d%d", &i, &j);
		getchar();
		pe = (ArcNode *)malloc(sizeof(ArcNode));
		pe->adjvex = j;						/* 邻接序号为j */
		pe->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = pe;

	}
}

int visute[MaxVerNum] = { 0 };

void DFSTraverse(ALGraph *G,int v)
{
	int w;
	ArcNode *p;
	printf("v%d ", v);
	visute[v]=1;
	p = G->vertices[v].firstarc;
	while (p != NULL)
	{
		w = p->adjvex;
		//printf("%d\n", visute[v]);
		if (visute[w]==0)
			DFSTraverse(G, w);
		p = p->nextarc;
	}
}
int main()
{
	ALGraph G;
	int v;

	CreateUDG(&G);
	printf("%d\n", (G.vertices[0].firstarc->adjvex));
	printf("输入起始点：");
	scanf("%c", &v);
	printf("以V%d为起点进行深度优先遍历:",v);
	DFSTraverse(&G,v);
	printf("\n");
	system("pause");
	return 0;
}



