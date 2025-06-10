
#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#define N 25
#define inf 0x3f3f3f3f

int n, m;
int k = 1;
queue<char> q;

bool DFS(int x, int n) {
    if (x > k)
        return false;
    if (n == m)
        return true;

    int temp = n;
    for (int i = 0; i < 2; i++) {
        if (i == 0)
            temp = n * 3;
        else
            temp = n / 2;

        if (DFS(x + 1, temp)) {
            if (i == 0)
                q.push('f');
            else
                q.push('g');
            return true;
        }
    }

    return false;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file!" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file!" << endl;
        inputFile.close();
        return 1;
    }

    inputFile >> n >> m;

    while (!DFS(0, n))
        k++;

    outputFile << k << '\n';
    while (!q.empty()) {
        outputFile << q.front();
        q.pop();
    }

    inputFile.close();
    outputFile.close();

    return 0;
}


