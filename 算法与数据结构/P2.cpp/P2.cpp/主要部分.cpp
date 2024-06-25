#include <iostream>
#include <cstdlib>
#include <queue>
#define Vertex short //用短整形节省空间
#define MAXSIZE 1001
#define SIX 6
using namespace std;
short a[MAXSIZE][MAXSIZE];//邻接矩阵
int N, M;

//插入边
void InsertEdge(Vertex V1, Vertex V2)
{
	a[V1][V2] = true;
	a[V2][V1] = true;
}

//初始化邻接矩阵图并录入边
void BuildGraph()
{
	Vertex V1, V2;
	int i, j;
	for (i = 0; i < MAXSIZE; i++)
		for (j = 0; j < MAXSIZE; j++)
			a[i][j] = false;//清空且初始化
	scanf_s("%d", &N);
	scanf_s("%d", &M);
	if(N!=0)
		for (i = 0; i < M; i++)
		{
			scanf_s("%hd %hd", &V1,&V2);
			InsertEdge(V1, V2);
		}
}

//广度遍历搜索 + 标识入队层级
int SDS_BFS(Vertex V)
{
	queue <Vertex>QUEUE;             //定义一个队列(cpp)
	int i, degree = 0, cnt = 0;      //degree-层级标识 cnt-结点计数器

	bool visited[MAXSIZE];          //访问记录表
	for (i = 0; i <= MAXSIZE; i++)   //初始化访问记录表
		visited[i] = false;

	QUEUE.push(degree);              //层级标识0入队
	QUEUE.push(V);                   //源节点入队-第0层-只有一个结点

	visited[V] = true;               //标记访问结点
	cnt++;//访问节点数+1

	while (!QUEUE.empty() && abs(degree) <= SIX)//队列不为空 且 层级小于6
	{
		V = QUEUE.front(); QUEUE.pop();        //队列中取出一个元素
		if (V <= 0)                            //如果出队元素为层级标识结点
		{
			QUEUE.push(--degree);              //下一层 层级标识结点 入队，为负数
			continue;                          //进入下轮循环
		}
		for (i=1;i<=N;i++)                     //图结点处理
			if (a[V][i] == true && visited[i] == false)  //如果邻接点未被访问
			{
				QUEUE.push(i);
				visited[i] = true;
				cnt++;
				//入队 ；访问 ；节点数+1 ；
			}
	}
	return cnt;//返回节点数个数值
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