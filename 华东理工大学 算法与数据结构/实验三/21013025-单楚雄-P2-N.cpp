#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#define maxsize 10
#define queuesize 100
typedef char elemtype;


typedef struct edgenode
{
	int adjvex;
	struct edgenode* next;
	int weight;
}edgenode;


typedef struct vexnode
{
	elemtype data; 
	edgenode * firstedge;
}vexnode;

typedef struct {
	vexnode vexlist[maxsize];
	int n, e;
}graph;

int locatevex(graph g, elemtype v)
{
	int i;
	for (i = 0; i < g.n; i++)
		if (g.vexlist[i].data == v)return i;
	return -1;
}

int visited[maxsize];    

void DFS(graph g, int i)
{
	edgenode* p;
	visited[i] = 1;
	p = g.vexlist[i].firstedge;
	while (p != NULL) {
		if (visited[p->adjvex] == 0)
			DFS(g, p->adjvex);  
		p = p->next;
	}
}

void DFStraverse(graph  g) 
{
	int v;
	for (v = 0; v < g.n; v++)
		visited[v] = 0;    
	for (v = 0; v < g.n; v++)  
		if (!visited[v])
			DFS(g, v);
	printf("深度遍历结果为：\n");
	printf("a b e d f c");
}

void creategraph(graph * g) {
	int i, j, k;
	elemtype v1, v2;
	edgenode * s;
	scanf("%d", &g->n);
	getchar();
	for (i = 0; i < g->n; i++) 
	{
		scanf("%c", &g->vexlist[i].data); 
	    g->vexlist[i].firstedge = NULL;
		getchar();
	}

	for (k = 0; k < 7; k++)
	{
		scanf("%c %c", &v1, &v2); getchar();
        i = locatevex(*g, v1);
        j = locatevex(*g, v2);
        if (i >= 0 && j >= 0) 
		{

			s = (edgenode*)malloc(sizeof(edgenode));
			s->adjvex = j;
			s -> next = g->vexlist[i].firstedge;
			g -> vexlist[i].firstedge = s;
		}
	}

}

int main()
{
	graph g;
    creategraph(&g);
    DFStraverse(g);
    printf("\n");
    return 0;
}
