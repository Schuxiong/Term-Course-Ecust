#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10000

struct Queue
{
	int data [MAXSIZE];
	int front, rear;
}Q;

bool Visited[MAXSIZE]; //�������

void InQueue(int x)   //��Ӳ���
{
	Q.data[Q.rear] = x;
	Q.rear++;
}

int DeQueue() //���Ӳ���
{
	int x = Q.data[Q.front];
	Q.front++;
	return x; //���س��ӵ�ֵ
}

int SDS_BFS(int** G, int v, int Nv) //���ȿռ��ȱ���
{
	int cnt = 1, level = 0, last = v, tail;//cnt-��������level-����
	int i;
	for (i = 0; i < v; i++)
	{
		Visited[i] = false
	}
	Q.front = Q.rear = 0;//��ս����

	Visited[v] = true;
	InQueue(v);
	while (Q.front < Q.rear)
	{
		int k = DeQueue();
		for (i = 0; i < v; i++)
		{
			if (G[k][i] && Visited[i] == false)
			{
				Visited[i] = true;
				InQueue(i);
				cnt++;
				tail = i;
			}
		}
		if (k == last)
		{
			level++;
			last = tail;
		}
		if (level == 6)
		{
			break;//�������
		}
	}
	return cnt;
}

int main()
{
	int i, E1, E2;
	int Nv;//�ڵ���
	int Ne;//����
	scanf_s("%d %d", &Nv, &Ne, );
	int** G = (int**)malloc((Nv + 1) * sizeof(int*));//ͼָ��ĳ�ʼ��

	for (i = 0; i < Nv; i++)
	{
		G[i] = (int*)malloc((Nv + 1) * sizeof(int));
		memset(G[i], 0, sizeof(int) * (Nv + 1));
		//��ʼ������
	}

	for (i = 0; i < Ne; i++)
	{
		scanf_s("%d %d", &E1, &E2);
		G[E1 - 1][E2 - 1] = 1;
		G[E2 - 1][E2 - 1] = 1;
	}

	for (i = 0; i < Nv; i++)
	{
		int count = SDS_BFS(G, i, Nv);
		printf("%d: %.2lf%%\n", i + 1, 100.0 * (double)count / (double)Nv);
	}
	return 0;
}
