#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void explore(vector<vector<char>>& grid, int i, int j) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '*') {
        return;
    }

    grid[i][j] = '*';  // Mark the current plot as visited

    // Explore all eight possible directions
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            explore(grid, i + dx, j + dy);
        }
    }
}

int countOilDeposits(vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '@') {
                explore(grid, i, j);
                count++;
            }
        }
    }

    return count;
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    int m, n;

    while (true) {
        infile >> m >> n;

        if (m == 0) {
            break;
        }

        vector<vector<char>> grid(m, vector<char>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                infile >> grid[i][j];
            }
        }

        int result = countOilDeposits(grid);
        outfile << result << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
