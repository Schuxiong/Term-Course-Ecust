#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

const int MAX = 100;
int n, m, d, min_weigth = 0x3f3f3f;
int ans[MAX];
int c[MAX][MAX], w[MAX][MAX];

struct node {
    int weight, cost, level, num, value[MAX];
    node(int a, int b, int c, int d) : weight(a), cost(b), level(c), num(d) {}

    bool operator<(const node& a) const {
        if (weight != a.weight)
            return weight > a.weight;
        else if (level != a.level)
            return a.level < level;
        else
            return num > a.num;
    }
};

priority_queue<node> q;

void initializePriorityQueue() {
    for (int i = 0; i < m; i++) {
        node temp = node(w[0][i], c[0][i], 0, i);
        if (temp.cost <= d) {
            temp.value[0] = i + 1;
            q.push(temp);
        }
    }
}

void search() {
    while (!q.empty()) {
        node temp = q.top();
        q.pop();

        if (temp.level < n - 1) {
            for (int i = 0; i < m; i++) {
                node t = node(temp.weight + w[temp.level + 1][i], temp.cost + c[temp.level + 1][i], temp.level + 1, i);
                if (t.level == n - 1) {
                    if (t.weight <= min_weigth && t.cost <= d) {
                        min_weigth = t.weight;
                        for (int i = 0; i < n - 1; i++) {
                            ans[i] = temp.value[i];
                        }
                        ans[n - 1] = i + 1;
                    }
                }
                else {
                    if (t.cost <= d) {
                        for (int i = 0; i < t.level; i++)
                            t.value[i] = temp.value[i];
                        t.value[t.level] = i + 1;
                        q.push(t);
                    }
                }
            }
        }
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> n >> m >> d;

    if (n <= 0 || m <= 0 || d <= 0) {
        out << "Invalid input." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            in >> c[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            in >> w[i][j];
        }
    }

    initializePriorityQueue();
    search();

    out << min_weigth << endl;

    for (int i = 0; i < n; i++) {
        out << ans[i] << " ";
    }

    in.close();
    out.close();

    return 0;
}
