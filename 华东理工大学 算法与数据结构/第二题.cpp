#include<bits/stdc++.h>


#define Vextype  char
#define   Edgetype   int
#define MaxVerNum  30           /* ��󶥵���� */

typedef  struct ArcNode			/*�߽��*/
{
	int adjvex;					/*�ñ���ָ��Ķ����λ��*/
	struct ArcNode * nextarc;	/*ָ����һ���ߵ�ָ��*/
}ArcNode;						
typedef struct VNode
{
	Vextype data;				/*������Ϣ*/
	ArcNode * firstarc;			/*ָ���һ�������ö���ıߵ�ָ��*/
}VNode, AdjList[MaxVerNum];		/*AdjList��ʾ�ڽӱ�����*/
typedef struct 
{
	AdjList vertices;			/*�ڽӱ�*/
	int vexnum, arcnum;			/*ͼ�ĵ�ǰ�������ͱ���*/
}ALGraph,*PALGraph;

void CreateUDG(ALGraph *G)	/*�����ڽӱ��ʾ������������ͼG*/
{
	int i,j,k;
	ArcNode *pe;
	printf("���붥�����ͱ���:");
	scanf("%d%d", &(G->vexnum), &(G->arcnum));/* ���붥�����ͱ��� */
	getchar();
	printf("���붥����Ϣ:\n");
	for (i = 0; i < G->vexnum; i++)				/*������㣬�����ͷ����*/
	{
		printf(" V%d=", i);
		scanf("%c", &(G->vertices[i].data)); /* ���붥����Ϣ����������� */
		getchar();
		G->vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G->arcnum; k++)			/*������ߣ������ڽӱ�*/
	{
		printf("�����(vi,vj)�Ķ������i%d,j%d���ո�ָ���:",i,j);
		scanf("%d%d", &i, &j);
		getchar();
		pe = (ArcNode *)malloc(sizeof(ArcNode));
		pe->adjvex = j;						/* �ڽ����Ϊj */
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
	printf("������ʼ�㣺");
	scanf("%c", &v);
	printf("��V%dΪ������������ȱ���:",v);
	DFSTraverse(&G,v);
	printf("\n");
	system("pause");
	return 0;
}



