//#include <fstream>
//#include <iostream>
//using namespace std;
//
//const int N = 100;
//const int M = 1e4;
//
//int n, s;
//int f1[2 * N + 10][N + 10], f2[2 * N + 10][N + 10];
//int a[2 * N + 10];
//
//int main() {
//    ifstream in("input1.txt");  // 打开输入文件
//    ofstream out("output1.txt");  // 打开输出文件
//
//    in >> n;
//    for (int i = 1; i <= n; i++) in >> a[i];
//
//    for (int i = 1; i <= n; i++) a[i + n] = a[i];
//    for (int i = 1; i <= 2 * n; i++) a[i] = a[i] + a[i - 1];
//    for (int i = 1; i <= 2 * n; i++) {
//        f1[i][1] = f2[i][1] = 0;
//    }
//    for (int l = 2; l <= n; l++) {
//        for (int i = 1; i <= 2 * n; i++) {
//            int j = i + l - 1;
//            if (j > 2 * n) break;
//            f1[i][l] = f1[i][1] + f1[i + 1][l - 1] + a[j] - a[i - 1];
//            f2[i][l] = f2[i][1] + f2[i + 1][l - 1] + a[j] - a[i - 1];
//            for (int k = 2; k <= l - 1; k++) {
//                f1[i][l] = max(f1[i][l], f1[i][k] + f1[i + k][l - k] + a[j] - a[i - 1]);
//                f2[i][l] = min(f2[i][l], f2[i][k] + f2[i + k][l - k] + a[j] - a[i - 1]);
//            }
//        }
//    }
//    int ma = f1[1][n], mi = f2[1][n];
//    for (int i = 2; i <= n; i++) {
//        ma = max(ma, f1[i][n]);
//        mi = min(mi, f2[i][n]);
//    }
//
//    out << mi << endl;  // 输出到文件
//    out << ma << endl;
//
//    in.close();  // 关闭输入文件
//    out.close();  // 关闭输出文件
//
//    return 0;
//}
