#include <iostream>
#include <cstdlib>
#include <queue>
#define Vertex short //�ö����ν�ʡ�ռ�
#define MAXSIZE 1001
#define SIX 6
using namespace std;
short a[MAXSIZE][MAXSIZE];//�ڽӾ���
int N, M;

//�����
void InsertEdge(Vertex V1, Vertex V2)
{
	a[V1][V2] = true;
	a[V2][V1] = true;
}

//��ʼ���ڽӾ���ͼ��¼���
void BuildGraph()
{
	Vertex V1, V2;
	int i, j;
	for (i = 0; i < MAXSIZE; i++)
		for (j = 0; j < MAXSIZE; j++)
			a[i][j] = false;//����ҳ�ʼ��
	scanf_s("%d", &N);
	scanf_s("%d", &M);
	if(N!=0)
		for (i = 0; i < M; i++)
		{
			scanf_s("%hd %hd", &V1,&V2);
			InsertEdge(V1, V2);
		}
}

//��ȱ������� + ��ʶ��Ӳ㼶
int SDS_BFS(Vertex V)
{
	queue <Vertex>QUEUE;             //����һ������(cpp)
	int i, degree = 0, cnt = 0;      //degree-�㼶��ʶ cnt-��������

	bool visited[MAXSIZE];          //���ʼ�¼��
	for (i = 0; i <= MAXSIZE; i++)   //��ʼ�����ʼ�¼��
		visited[i] = false;

	QUEUE.push(degree);              //�㼶��ʶ0���
	QUEUE.push(V);                   //Դ�ڵ����-��0��-ֻ��һ�����

	visited[V] = true;               //��Ƿ��ʽ��
	cnt++;//���ʽڵ���+1

	while (!QUEUE.empty() && abs(degree) <= SIX)//���в�Ϊ�� �� �㼶С��6
	{
		V = QUEUE.front(); QUEUE.pop();        //������ȡ��һ��Ԫ��
		if (V <= 0)                            //�������Ԫ��Ϊ�㼶��ʶ���
		{
			QUEUE.push(--degree);              //��һ�� �㼶��ʶ��� ��ӣ�Ϊ����
			continue;                          //��������ѭ��
		}
		for (i=1;i<=N;i++)                     //ͼ��㴦��
			if (a[V][i] == true && visited[i] == false)  //����ڽӵ�δ������
			{
				QUEUE.push(i);
				visited[i] = true;
				cnt++;
				//��� ������ ���ڵ���+1 ��
			}
	}
	return cnt;//���ؽڵ�������ֵ
}
int main()
{
	Vertex V;
	int n;
	BuildGraph();
	for (V = 1; V <= N; V++)
	{
		n = SDS_BFS(V);
		printf("%d: %.2f\n", V, (float)n * 100 / N);
	}
	return 0;
}