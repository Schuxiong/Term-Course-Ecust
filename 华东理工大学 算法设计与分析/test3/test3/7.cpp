#include <iostream>
#include <cmath>
using namespace std;

// 判断在当前位置放置皇后是否合法
bool isSafe(int board[], int row, int col, int n) {
    // 检查列是否有皇后
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// 递归函数，尝试在当前行放置皇后
void solveNQueens(int board[], int row, int n, int& count) {
    if (row == n) {
        // 找到一种放置方式
        count++;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            // 在当前位置放置皇后
            board[row] = col;
            // 递归放置下一行的皇后
            solveNQueens(board, row + 1, n, count);
        }
    }
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        int count = 0;
        int* board = new int[n]; // 使用动态分配数组
        solveNQueens(board, 0, n, count);
        delete[] board; // 释放动态分配的数组
        cout << "result="<<count<<endl;
    }

    return 0;
}
