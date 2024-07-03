//#include<string.h>
//#include<stdio.h>
//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//char maze[7][7];
//int direct[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//int n, m, t, dx, dy;
//bool flag;
//void dfs(int x, int y, int step)
//{
//    int i, p, x1, y1;
//    if (x <= 0 || x > n || y <= 0 || y > m)
//        return;
//    if (x == dx && y == dy && step == t)
//    {
//        flag = 1;
//        return;
//    }
//    p = (t - step) - abs(x - dx) - abs(y - dy);
//    if (p < 0 || p & 1)
//        return;
//    for (i = 0; i < 4; i++)
//    {
//        x1 = x + direct[i][0];
//        y1 = y + direct[i][1];
//        if (maze[x1][y1] != 'X')
//        {
//            maze[x1][y1] = 'X';
//            dfs(x1, y1, step + 1);
//            if (flag)
//                return;
//            maze[x1][y1] = '.';
//        }
//    }
//    return;
//}
//int main()
//{
//    int i, j, sx, sy, wall;
//    while (scanf_s("%d%d%d", &n, &m, &t) && (m + n + t))
//    {
//        wall = 0;
//        for (i = 1; i <= n; i++)
//        {
//            for (j = 1; j <= m; j++)
//            {
//                cin >> maze[i][j];
//                if (maze[i][j] == 'S')
//                {
//                    sx = i;
//                    sy = j;
//                }
//                else if (maze[i][j] == 'D')
//                {
//                    dx = i;
//                    dy = j;
//                }
//                else if (maze[i][j] == 'X')
//                    wall++;
//            }
//        }
//        flag = 0;
//        maze[sx][sy] = 'X';
//        dfs(sx, sy, 0);
//        if (n * m - wall <= t)
//        {
//            printf("NO\n");
//            continue;
//        }
//        if (flag)
//            printf("YES\n");
//        else
//            printf("NO\n");
//    }
//    return 0;
//}