#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y, steps;
    Point(int x, int y, int steps) : x(x), y(y), steps(steps) {}
};

int bfs(vector<vector<char>>& prison, int startX, int startY) {
    int N = prison.size();
    int M = prison[0].size();

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<Point> q;
    q.push(Point(startX, startY, 0));

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        int x = current.x;
        int y = current.y;
        int steps = current.steps;

        if (prison[x][y] == 'a') {
            return steps;
        }

        // Try moving in four directions
        int dx[] = { 0, 0, 1, -1 };
        int dy[] = { 1, -1, 0, 0 };

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && prison[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(Point(nx, ny, steps + 1));
            }
        }
    }

    return -1; // No path found
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<vector<char>> prison(N, vector<char>(M));
        int startX, startY;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> prison[i][j];
                if (prison[i][j] == 'r') {
                    startX = i;
                    startY = j;
                }
            }
        }

        int result = bfs(prison, startX, startY)+1;

        if (result == -1) {
            cout << "Poor ANGEL has to stay in the prison all his life." << endl;
        }
        else {
            cout << result  << endl;
        }
    }

    return 0;
}
