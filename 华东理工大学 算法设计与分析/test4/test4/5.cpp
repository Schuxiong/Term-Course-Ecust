#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>

using namespace std;

struct node
{
    int a;
    int b;
    int c;
    int step;
};

int s, n, m;
int flag;
int ans;
int vis[101][101][101];

void bfs()
{
    queue<node> q;
    node p;
    p.a = s;
    p.b = 0;
    p.c = 0;
    p.step = 0;
    vis[s][0][0] = 1;
    q.push(p);
    node t;
    while (!q.empty())
    {
        node k = q.front();
        q.pop();
        if ((k.a + k.b == s && k.a == k.b) || (k.a + k.c == s && k.a == k.c) || (k.b + k.c == s && k.b == k.c)) //要平分才行
        {
            flag = 1;
            ans = k.step; //输出倒的次数
            return;
        }
        for (int i = 0; i < 6; i++)
        {
            if (i == 0) //a->b
            {
                if (k.a + k.b > n)
                {
                    t.a = k.a + k.b - n;
                    t.b = n;
                    t.c = k.c;
                }
                else
                {
                    t.b = k.a + k.b;
                    t.a = 0;
                    t.c = k.c;
                }
            }
            else if (i == 1) //a->c
            {
                if (k.a + k.c > m)
                {
                    t.a = k.a + k.c - m;
                    t.c = m;
                    t.b = k.b;
                }
                else
                {
                    t.c = k.a + k.c;
                    t.a = 0;
                    t.b = k.b;
                }
            }
            else if (i == 2) //b->c
            {
                if (k.b + k.c > m)
                {
                    t.b = k.b + k.c - m;
                    t.c = m;
                    t.a = k.a;
                }
                else
                {
                    t.c = k.b + k.c;
                    t.b = 0;
                    t.a = k.a;
                }
            }
            else if (i == 3) //b->a//这里不进行if-else是因为可乐桶绝不会溢出来，他的容量是最大的
            {
                t.a = k.a + k.b;
                t.b = 0;
                t.c = k.c;
            }
            else if (i == 4) //c->a
            {
                t.a = k.a + k.c;
                t.c = 0;
                t.b = k.b;
            }
            else if (i == 5) //c->b
            {
                if (k.b + k.c > n)
                {
                    t.c = k.b + k.c - n;
                    t.b = n;
                    t.a = k.a;
                }
                else
                {
                    t.b = k.b + k.c;
                    t.c = 0;
                    t.a = k.a;
                }
            }
            if (vis[t.a][t.b][t.c] == 0) //基本BFS入队列操作
            {
                t.step = k.step + 1;
                vis[t.a][t.b][t.c] = 1;
                q.push(t);
            }
        }
    }
}

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    while (true)
    {
        infile >> s >> n >> m;

        if ((s == 0 && n == 0 && m == 0))
        {
            break;
        }

        memset(vis, 0, sizeof(vis));
        flag = 0;
        ans = 0;

        if (s % 2 == 1) //奇数绝对不可能平分，因为必须保证第三个杯子为空切没有小数出现
        {
            outfile << "NO" << endl;
            break;
            
        }
        else
        {
            bfs();
            if (flag)
            {
                outfile << ans << endl;
                break;
            }
            else
            {
                outfile << "NO" << endl;
                break;
            }
        }
    }

    infile.close();
    outfile.close();

    return 0;
}
