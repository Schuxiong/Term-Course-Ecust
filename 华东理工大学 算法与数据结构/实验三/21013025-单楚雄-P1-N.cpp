#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAXN = 100;
int Graph[MAXN][MAXN];//�ڽӾ���

int Nv;
int sx, ex, cost;//����ţ��ص��ţ�Ȩֵ

int main()
{
	printf("����������\n");
	cin >> Nv ;
	printf("����������ţ��յ��ţ�Ȩ��\n");
	for (int i = 0; i < 10; i++)//��Ŵ�0��ʼ
	{
		cin >> sx >> ex >> cost;
		Graph[sx][ex] = cost;
	}
    printf("�ڽӾ���Ϊ��\n");
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
