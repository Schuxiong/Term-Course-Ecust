//#include <iostream>
//#include <fstream>
//#include <algorithm>
//using namespace std;
//
//int n;
//int c;
//int final = 0;  // 当前元素加到最后一个元素的总和
//int sum = 0;    // 已选元素之和
//int a[10000];   // 原数组
//bool b[10000];  // 判断元素选不选
//
//bool Backtrack(int t) {
//    if (sum == c) return true;  // 已找到
//    if (t >= n) return false;    // 未找到
//
//    final -= a[t];   // 先减去该元素
//
//    if (sum + a[t] <= c) {    // 如果已选元素之和加上该元素小于等于c，则
//        b[t] = true;    // 选上该元素
//        sum += a[t];    // 已选元素之和加上该元素
//        if (Backtrack(t + 1)) return true;   // 下一个元素Backtrack成功返回true
//        sum -= a[t];    // 否则减回去
//    }
//
//    if (sum + final >= c) {     // 如果已选元素之和加上当前元素加到最后一个元素的总和大于等于c，则
//        b[t] = false;    // 不选当前元素
//        if (Backtrack(t + 1)) return true;  // 下一个元素Backtrack成功返回true
//    }
//
//    final += a[t];   // 加回去
//    return false;   // 未找到
//}
//
//int main() {
//    ifstream inputFile("input.txt");  // 输入文件名为input.txt
//    ofstream outputFile("output.txt");  // 输出文件名为output.txt
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
//    inputFile >> n >> c;
//
//    for (int i = 0; i < n; i++) {
//        inputFile >> a[i];
//        final += a[i];
//    }
//
//    sort(a, a + n);  // 对数组进行排序
//
//    if (!Backtrack(0))
//        outputFile << "No Solution!" << endl;
//    else {
//        for (int i = 0; i < n; i++) {
//            if (b[i]) outputFile << a[i] << " ";  // 如果该元素为true，则输出
//        }
//        outputFile << endl;  // 输出换行，美化输出
//    }
//
//    inputFile.close();
//    outputFile.close();
//
//    return 0;
//}
