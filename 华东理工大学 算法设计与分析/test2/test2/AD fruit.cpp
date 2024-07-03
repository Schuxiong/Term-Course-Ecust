#include <iostream>
#include <string>
#include <vector>
using namespace std;

string shortestName(const string& fruit1, const string& fruit2) {
    int len1 = fruit1.length();
    int len2 = fruit2.length();

    // Create a table to store the lengths of matching suffixes
    vector<vector<int>> matchLength(len1 + 1, vector<int>(len2 + 1, 0));

    // Fill in the table with the lengths of matching suffixes
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            if (fruit1[i] == fruit2[j]) {
                matchLength[i][j] = matchLength[i + 1][j + 1] + 1;
            }
        }
    }

    // Find the maximum overlap between the two fruit names
    int overlap = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            overlap = max(overlap, matchLength[i][j]);
        }
    }

    // Combine the fruit names, excluding the overlapping part
    return fruit1 + fruit2.substr(overlap);
}

int main() {
    string fruit1, fruit2;

    while (cin >> fruit1 >> fruit2) {
        string result = shortestName(fruit1, fruit2);
        cout << result << endl;
    }

    return 0;
}
