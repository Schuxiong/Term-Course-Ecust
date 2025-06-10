//#include <iostream>
//#include <fstream>
//#include <vector>
//using namespace std;
//
//const int MAX = 150;
//int board[MAX][6];
//int solu[MAX][6];
//int n;
//int ans = 0;
//int used[MAX];
//char color[MAX];
//
//void out(int edge[], ofstream& outputFile) {
//    int i, j, k, a, b, c, d;
//    for (i = 0; i < 2; i++) {
//        for (j = 0; j < n; j++)
//            used[j] = 0;
//        do {
//            j = 0;
//            d = c = -1;
//            while (j < n && used[j] > 0)
//                j++;
//            if (j < n)
//                do {
//                    a = board[j][edge[i * n + j] * 2];
//                    b = board[j][edge[i * n + j] * 2 + 1];
//                    if (b == d)
//                        swap(a, b);
//                    solu[j][i * 2] = a;
//                    solu[j][i * 2 + 1] = b;
//                    used[j] = 1;
//                    if (c < 0)
//                        c = a;
//                    d = b;
//                    for (k = 0; k < n; k++)
//                        if (used[k] == 0 && (board[k][edge[i * n + k] * 2] == b || board[k][edge[i * n + k] * 2 + 1] == b))
//                            j = k;
//                } while (b != c);
//        } while (j < n);
//    }
//    for (j = 0; j < n; j++) {
//        k = 3 - edge[j] - edge[j + n];
//        a = board[j][k * 2];
//        b = board[j][k * 2 + 1];
//        solu[j][4] = a;
//        solu[j][5] = b;
//    }
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < 6; j++)
//            outputFile << color[solu[i][j]];
//        outputFile << endl;
//    }
//}
//
//void search(ofstream& outputFile) {
//    int i, t, cube;
//    bool ok, newg, over;
//    vector<int> vert(n, 0);
//    vector<int> edge(n * 2);
//    for (i = 0; i < n; i++)
//        vert[i] = 0;
//    t = -1;
//    newg = true;
//    while (t > -2) {
//        t++;
//        cube = t % n;
//        if (newg)
//            edge[t] = -1;
//        over = false;
//        ok = false;
//        while (!ok && !over) {
//            edge[t]++;
//            if (edge[t] > 2)
//                over = true;
//            else
//                ok = (t < n || edge[t] != edge[cube]);
//        }
//        if (!over) {
//            if (++vert[board[cube][edge[t] * 2]] > 2 + t / 2 * 2)
//                ok = false;
//            if (++vert[board[cube][edge[t] * 2 + 1]] > 2 + t / 2 * 2)
//                ok = false;
//            if (t % n == n - 1 && ok)
//                for (i = 0; i < n; i++)
//                    if (vert[i] > 2 + t / n * 2)
//                        ok = false;
//            if (ok) {
//                if (t == n * 2 - 1) {
//                    ans++;
//                    out(edge.data(), outputFile);
//                    return;
//                }
//                else
//                    newg = true;
//            }
//            else {
//                --vert[board[cube][edge[t] * 2]];
//                --vert[board[cube][edge[t] * 2 + 1]];
//                t--;
//                newg = false;
//            }
//        }
//        else {
//            t--;
//            if (t > -1) {
//                cube = t % n;
//                --vert[board[cube][edge[t] * 2]];
//                --vert[board[cube][edge[t] * 2]];
//            }
//            t--;
//            newg = false;
//        }
//    }
//}
//
//int main() {
//    ifstream inputFile("input.txt");
//    ofstream outputFile("output.txt");
//
//    if (!inputFile.is_open()) {
//        cerr << "Error: Unable to open input file!" << endl;
//        return 1;
//    }
//
//    if (!outputFile.is_open()) {
//        cerr << "Error: Unable to open output file!" << endl;
//        inputFile.close();
//        return 1;
//    }
//
//    inputFile >> n;
//
//    for (int i = 0; i < n; i++) {
//        inputFile >> color[i];
//    }
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < 6; j++) {
//            inputFile >> board[i][j];
//        }
//    }
//
//    search(outputFile);
//
//    if (ans == 0)
//        outputFile << "No Solution!" << endl;
//
//    inputFile.close();
//    outputFile.close();
//
//    return 0;
//}
