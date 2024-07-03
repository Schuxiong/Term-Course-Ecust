#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxVertexNum 10000

struct Queue {               //队列的结构体类型
    int Data[MaxVertexNum];
    int front, rear;
}Q;

bool Visited[MaxVertexNum];  //标记数组

void InQueue(int x)          //入队操作
{
    Q.Data[Q.rear] = x;
    Q.rear++;
}

int DeQueue()                //出队操作
{
    int x = Q.Data[Q.front];
    Q.front++;
    return x;                //返回出队的值
} 

int BFS(int** G, int v, int Nv)      //广度优先遍历
{
    int h, l;
    int i, cnt = 1, level = 0, last = v, tail;
    for (i = 0; i < v; i++) {
        Visited[i] = false;
    }
    Q.front = Q.rear = 0;
    Visited[v] = true;
    InQueue(v);
    while (Q.front < Q.rear) {
        int k = DeQueue();
        for (i = 0; i < v; i++)
        {
            if (G[k][i] && Visited[i] == false) {
                Visited[i] = true;
                InQueue(i);
                cnt++;
                tail = i;
            }
        }
        if (k == last)
        {
            level++; //层数 
            last = tail;
        }
        if (level == 6)
        {
            break;
        }
    }
    return cnt;
}

int main()
{
    int i, e1, e2;
    int Nv;     //结点数 
    int Ne;     //边数
    scanf("%d %d", &Nv, &Ne);
    int** G = (int**)malloc((Nv + 1) * sizeof(int*));

    for (i = 0; i < Nv; i++) 
    {
        G[i] = (int*)malloc((Nv + 1) * sizeof(int));
        memset(G[i], 0, sizeof(int) * (Nv + 1));      //初始化数组为0 
    } 

    for (i = 0; i < Ne; i++) 
    {
        scanf("%d %d", &e1, &e2);
        G[e1 - 1][e2 - 1] = 1;
        G[e2 - 1][e1 - 1] = 1;
    }

    for (i = 0; i < Nv; i++) 
    {
        int count = BFS(G, i, Nv);
        printf("%d: %.2lf%%\n", i + 1, 100.0 * (double)count / (double)Nv);
    }

    return 0;
}