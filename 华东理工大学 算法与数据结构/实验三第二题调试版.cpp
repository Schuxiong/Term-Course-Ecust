#include <iostream>
#include <deque>
#include <iomanip>
#define ElementType int
#define Vertex int
 
typedef struct _ENode
{
	Vertex V1;
	Vertex V2;
}Edge;
 
typedef struct _GNode
{
	int num_of_array;//�����Ǿ���洢�����Ժ�һ��Ķ�ά��һ��
	int Nv;//������
	int Ne;//����
	ElementType *G;//�������ٽӾ���,һά�����ά
}Graph;
 
using namespace std;
 
void creat_Graph(Graph *, int num_v, int num_e);
void insert_Edge(Graph *, Edge);
void Six_Degrees(Graph *);
double Calculate_Six_Percent(Graph *, Vertex, int degrees, bool visited[]);
void print(Graph *);
 
double *percent;
 
int main()
{
	int N, M;
	cin >> N >> M;
	Graph *graph = new Graph;
	creat_Graph(graph, N, M);
	for (int i = 0; i < M; i++)
	{
		Edge edge;
		cin >> edge.V1 >> edge.V2;
		insert_Edge(graph, edge);
	}
	percent = new double[graph->num_of_array];
	Six_Degrees(graph);
	print(graph);
 
    return 0; 
}
 
void creat_Graph(Graph *graph, int num_v, int num_e)
{
	graph->num_of_array = num_v * (num_v + 1) / 2;
	graph->Nv = num_v;
	graph->Ne = num_e;
	graph->G = new ElementType[graph->num_of_array];
	for (int i = 0; i < graph->num_of_array; i++)	//�������ٽӾ����ʼ��
		graph->G[i] = 0;
} 
 
void insert_Edge(Graph *graph, Edge edge)
{
	edge.V1 -= 1;//������Ǵ�1��ʼ���������˳�������0��ʼ
	edge.V2 -= 1;
	if (edge.V1 < edge.V2)
		graph->G[edge.V2*(edge.V2 + 1) / 2 + edge.V1] = 1;
	else
		graph->G[edge.V1*(edge.V1 + 1) / 2 + edge.V2] = 1;
}
 
void Six_Degrees(Graph *graph)
{
	bool *visited = new bool[graph->Nv];
	for (Vertex i = 0; i < graph->Nv; i++)
	{
		for (int i = 0; i < graph->Nv; i++)//��ʼ��visited��visitedֻ��Nv������
			visited[i] = 0;
		percent[i] = Calculate_Six_Percent(graph, i, 1, visited);//percentҲֻ��Nv������
	}
}
 
double Calculate_Six_Percent(Graph *graph, Vertex start_V, int degrees, bool visited[])
{
	Vertex *queue = new Vertex[graph->num_of_array + 1];
	int front = 0, rear = 0, last = 0;
	int num_six_degrees = 0;//������6�ȵĶ�����
	Vertex V = start_V;
 
	visited[V] = 1;
	queue[rear++] = V;//���
	while (front != rear && degrees <= 6)
	{
		V = queue[front++];//����
		Vertex target_V = 0;//�������Ǿ���Ĺ�ϵ��i���ܱ�ʾ���㣬���� target_V ��ʾҪ�붥�� V ���жϵĶ���
		Vertex start_TLine = V * (V + 1) / 2;
		Vertex start_VLine = start_TLine + V;
		for (Vertex i = start_TLine; i < start_TLine + V; i++)				//�������򶥵�
		{
			if (graph->G[i] == 1 && visited[target_V] == 0) {				//�б���δ�����ʹ�
				queue[rear++] = target_V;
				visited[target_V] = 1;
				num_six_degrees++;
			}	
			target_V++;
		}
		int k = 0;
		for (Vertex i = start_VLine; i < graph->num_of_array; i = i + V + k)//�������򶥵�
		{
			k++;
			if (graph->G[i] == 1 && visited[target_V] == 0) {
				queue[rear++] = target_V;
				visited[target_V] = 1;
				num_six_degrees++;
			}
			target_V++;
		}
		if (last == front - 1) {
			degrees++;
			last = rear - 1;
		}
	}
	return (double)(num_six_degrees + 1) / graph->Nv;
}
 
void print(Graph *graph)
{
	int flag = 1;
	cout << setprecision(2) << setiosflags(ios::fixed);
	for (int i = 0; i < graph->Nv; i++)
	{
		if (flag)
			flag = 0;
		else
			cout << endl;
		cout << i+1 << ": " << percent[i] * 100 << "%";
	}
}
}
