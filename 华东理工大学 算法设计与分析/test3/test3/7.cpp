#include <iostream>
#include <cmath>
using namespace std;

// �ж��ڵ�ǰλ�÷��ûʺ��Ƿ�Ϸ�
bool isSafe(int board[], int row, int col, int n) {
    // ������Ƿ��лʺ�
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// �ݹ麯���������ڵ�ǰ�з��ûʺ�
void solveNQueens(int board[], int row, int n, int& count) {
    if (row == n) {
        // �ҵ�һ�ַ��÷�ʽ
        count++;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            // �ڵ�ǰλ�÷��ûʺ�
            board[row] = col;
            // �ݹ������һ�еĻʺ�
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
        int* board = new int[n]; // ʹ�ö�̬��������
        solveNQueens(board, 0, n, count);
        delete[] board; // �ͷŶ�̬���������
        cout << "result="<<count<<endl;
    }

    return 0;
}
