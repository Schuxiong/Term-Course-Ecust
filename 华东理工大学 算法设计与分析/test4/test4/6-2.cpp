
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 105;
int G[MAX][MAX];
vector<int> bestx;
int w[MAX];  // �����Ȩ
int n, e;    

class Node {
public:
    int dep;          // ��ǰ��
    int val;          // ��������Ȩֵ֮��
    vector<int> x;    // ������
    vector<int> c;    // ���ϵ���һ������

    Node() {
        x.resize(MAX);
        c.resize(MAX);
    }

    // ��ǰ���г���С���ȳ�����
    bool operator<(const Node& node) const {
        return val >= node.val;
    }
};

priority_queue<Node> q;

// �ж�ͼ�Ƿ�����ȫ����
bool cover(Node E) {
    for (int i = 1; i <= n; i++)
        if (E.x[i] == 0 && E.c[i] == 0)
            return false;
    return true;
}

// ��ӽ��
void addNode(Node enode, int i, int v, bool isLeft) {
    Node now;
    now.dep = i;
    copy(enode.x.begin(), enode.x.end(), now.x.begin());
    copy(enode.c.begin(), enode.c.end(), now.c.begin());
    if (isLeft) {
        now.val = v + w[i];
        now.x[i] = 1;
        for (int j = 1; j <= n; j++)
            if (G[j][i])
                now.c[j]++;
    }
    else {
        now.val = v;
        now.x[i] = 0;
    }
    q.push(now);
}

int search() {
    Node enode;
    for (int j = 1; j <= n; j++) {
        enode.x[j] = 0;
        enode.c[j] = 0;
    }
    int best;
    int i = 1;
    int val = 0;
    while (true) {
        if (i > n) {
            if (cover(enode)) {
                best = val;
                copy(enode.x.begin(), enode.x.end(), bestx.begin());
                break;
            }
        }
        else {
            if (!cover(enode))
                addNode(enode, i, val, true);
            addNode(enode, i, val, false);
        }
        if (q.empty())
            break;
        else {
            enode = q.top();
            q.pop();
            i = enode.dep + 1;
            val = enode.val;
        }
    }
    return best;
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Error opening files." << endl;
        return 1;
    }

    inFile >> n >> e;

    for (int i = 1; i <= n; i++) {
        inFile >> w[i];
    }

    int a, b;
    memset(G, 0, sizeof(G));

    for (int i = 1; i <= e; i++) {
        inFile >> a >> b;
        G[a][b] = G[b][a] = 1;
    }

    bestx.resize(MAX);

    outFile << search() << endl;

    for (int i = 1; i <= n; i++) {
        if (i > 1)
            outFile << " ";
        outFile << bestx[i];
    }

    outFile << endl;

    inFile.close();
    outFile.close();

    return 0;
}

