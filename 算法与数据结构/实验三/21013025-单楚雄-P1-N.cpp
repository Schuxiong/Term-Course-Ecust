#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAXN = 100;
int Graph[MAXN][MAXN];//邻接矩阵

int Nv;
int sx, ex, cost;//起点编号，重点编号，权值

int main()
{
	printf("请输入结点数\n");
	cin >> Nv ;
	printf("请输入起点编号，终点编号，权重\n");
	for (int i = 0; i < 10; i++)//编号从0开始
	{
		cin >> sx >> ex >> cost;
		Graph[sx][ex] = cost;
	}
    printf("邻接矩阵为：\n");
	for (int i = 0; i < Nv; i++)
	{
		for (int j = 0; j < Nv; j++)
		{
			if (Graph[i][j])
				cout << Graph[i][j] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
	return 0;
}
