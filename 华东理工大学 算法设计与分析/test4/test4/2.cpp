#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

using namespace std;

struct Point {
    int x, y, z, time;
    Point(int x, int y, int z, int time) : x(x), y(y), z(z), time(time) {}
};

int main() {
    // 将标准输入重定向到文件
    freopen("input.txt", "r", stdin);
    // 将标准输出重定向到文件
    freopen("output.txt", "w", stdout);

    int K;
    scanf("%d", &K);

    while (K--) {
        int A, B, C, T;
        scanf("%d%d%d%d", &A, &B, &C, &T);

        int castle[50][50][50];
        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                for (int k = 0; k < C; ++k) {
                    scanf("%d", &castle[i][j][k]);
                }
            }
        }

        queue<Point> q;
        int visited[50][50][50] = { 0 };

        q.push(Point(0, 0, 0, 0));
        visited[0][0][0] = 1;

        int dx[] = { 1, -1, 0, 0, 0, 0 };
        int dy[] = { 0, 0, 1, -1, 0, 0 };
        int dz[] = { 0, 0, 0, 0, 1, -1 };

        while (!q.empty()) {
            Point current = q.front();
            q.pop();

            int x = current.x;
            int y = current.y;
            int z = current.z;
            int time = current.time;

            if (x == A - 1 && y == B - 1 && z == C - 1) {
                if (time <= T) {
                    printf("%d\n", time);
                }
                else {
                    printf("-1\n");
                }
                break;
            }

            for (int i = 0; i < 6; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];

                if (nx >= 0 && nx < A && ny >= 0 && ny < B && nz >= 0 && nz < C &&
                    castle[nx][ny][nz] == 0 && !visited[nx][ny][nz]) {
                    visited[nx][ny][nz] = 1;
                    q.push(Point(nx, ny, nz, time + 1));
                }
            }
        }

        // Add a newline to ensure correct output flushing
        printf("\n");
    }

    return 0;
}
