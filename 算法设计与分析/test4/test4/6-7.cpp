#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

namespace Test {

    struct BoardNode {
        int s, cd;
        std::vector<int> x;

        bool operator<(const BoardNode& other) const {
            return cd > other.cd; // Note: using greater than for min heap
        }

        int len(const std::vector<std::vector<int>>& conn, int ii) const {
            int sum = 0;
            for (int i = 0; i < ii; i++)
                for (int j = i + 1; j < ii; j++) {
                    int dist = x[i] > x[j] ? x[i] - x[j] : x[j] - x[i];
                    sum += conn[i][j] * dist;
                }
            return sum;
        }
    };

    const int MAX = 100000;
    int n;
    std::vector<int> p;
    std::vector<std::vector<int>> B;

    int BBArrangeBoards(const std::vector<std::vector<int>>& conn, int n) {
        std::priority_queue<BoardNode> H;
        BoardNode E;
        E.x.resize(n);
        E.s = 0;
        E.cd = 0;
        for (int i = 0; i < n; i++) E.x[i] = i + 1;
        int bestd = MAX;

        while (E.cd < bestd) {
            if (E.s == n - 1) {
                int ld = E.len(conn, n);
                if (ld < bestd) {
                    p = E.x;
                    bestd = ld;
                }
            }
            else {
                for (int i = E.s + 1; i < n; i++) {
                    BoardNode N;
                    N.x.resize(n);
                    N.s = E.s + 1;
                    for (int j = 0; j < n; j++) N.x[j] = E.x[j];
                    std::swap(N.x[N.s], N.x[i]);
                    N.cd = N.len(conn, N.s);
                    if (N.cd < bestd) H.push(N);
                }
            }

            if (H.empty()) return bestd;
            else {
                E = H.top();
                H.pop();
            }
        }

        return bestd;
    }

} // namespace Test

int main() {
    using namespace Test;
    std::ios::sync_with_stdio(false);

    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    while (true) {
        inputFile >> n;

        if (n == 0) break;

        p.resize(n);
        B.resize(n, std::vector<int>(n));

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                inputFile >> B[i][j];

        outputFile << BBArrangeBoards(B, n) << '\n';
        for (int i = 0; i < n; i++)
            outputFile << p[i] << " ";
        break;
        outputFile << '\n';

    }

    inputFile.close();
    outputFile.close();

    return 0;
}
