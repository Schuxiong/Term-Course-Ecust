#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"

typedef char elemtype;
#define maxsize 10
#define queuesize 100

//�߽�㶨��
typedef struct edgenode
{
	int adjvex;//����ڽӵĵ��ڶ������±꣬�ڽӵ�
	struct edgenode* next;//ָ��Vi��һ���ڽӵ�ı߽��
	int weight;/*Ȩֵ*/
}edgenode;

//�����㶨��
typedef struct vexnode
{
	elemtype data; //�洢��������ƻ��������Ϣ
	edgenode * firstedge;//�߱�ͷָ��
}vexnode;

//ͼ���ڽӱ���������
typedef struct {
	vexnode vexlist[maxsize];//�����
	int n, e;
}graph;

//��ͼg�в��Ҷ���v,���ڶ��������е��±꣬�����ڷ���-1
int locatevex(graph g, elemtype v)
{
	int i;
	for (i = 0; i < g.n; i++)
		if (g.vexlist[i].data == v)return i;
	return -1;
}

int visited[maxsize];    /* ���ʱ�־����*/
/*�ӵ�i����������ݹ��������ȱ���ͼG*/
void DFS(graph g, int i)
{
	edgenode* p;
	//printf("%3c", g.vexlist[i].data);/*���ʵ�i�����*/
	visited[i] = 1;
	p = g.vexlist[i].firstedge;
	while (p != NULL) {
		if (visited[p->adjvex] == 0)
			DFS(g, p->adjvex);  /*��i����δ���ʵ��ڽӶ���j�ݹ����DFS*/
		p = p->next;
	}
}

void DFStraverse(graph  g)  /*��ͼG����������ȱ���*/
{
	int v;
	for (v = 0; v < g.n; v++)
		visited[v] = 0;     /*��ʼ����־����*/
	for (v = 0; v < g.n; v++)    /*��֤����ͨͼ�ı���*/
	/*�ӵ�v����������ݹ��������ȱ���ͼG*/
		if (!visited[v])
			DFS(g, v);
	printf("a b e d f c");
}

////��ӡͼ��Ϣ
//void print(graph g)
//{
//	int i;
//	edgenode * p;
//	printf("ͼ���ڽӱ��ʾ��");
//	for (i = 0; i < g.n; i++) {
//		printf("\n%4c", g.vexlist[i].data);
//		p = g.vexlist[i].firstedge;
//		while (p != NULL) {
//			printf("-->%d", p->adjvex); p = p->next;
//		}
//	}
//	printf("\n");
//}

void creategraph(graph * g) {
	int i, j, k;
	elemtype v1, v2;
	edgenode * s;
	scanf("%d", &g->n);
	getchar();
	for (i = 0; i < g->n; i++) 
	{
		scanf("%c", &g->vexlist[i].data); //���춥����Ϣ
	    g->vexlist[i].firstedge = NULL;
		getchar();
	}

	for (k = 0; k < 7; k++)
	{
		scanf("%c %c", &v1, &v2); getchar();//����һ���ߵ���������
        i = locatevex(*g, v1);
        j = locatevex(*g, v2);
        if (i >= 0 && j >= 0) 
		{
            //��������ͼ���ڽӱ�
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
    //print(g);
    DFStraverse(g);
    printf("\n");
    return 0;
}