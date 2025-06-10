//#include <iostream>
//#include <fstream>
//#include <algorithm>
//using namespace std;
//
//int n;
//int c;
//int final = 0;  // ��ǰԪ�ؼӵ����һ��Ԫ�ص��ܺ�
//int sum = 0;    // ��ѡԪ��֮��
//int a[10000];   // ԭ����
//bool b[10000];  // �ж�Ԫ��ѡ��ѡ
//
//bool Backtrack(int t) {
//    if (sum == c) return true;  // ���ҵ�
//    if (t >= n) return false;    // δ�ҵ�
//
//    final -= a[t];   // �ȼ�ȥ��Ԫ��
//
//    if (sum + a[t] <= c) {    // �����ѡԪ��֮�ͼ��ϸ�Ԫ��С�ڵ���c����
//        b[t] = true;    // ѡ�ϸ�Ԫ��
//        sum += a[t];    // ��ѡԪ��֮�ͼ��ϸ�Ԫ��
//        if (Backtrack(t + 1)) return true;   // ��һ��Ԫ��Backtrack�ɹ�����true
//        sum -= a[t];    // �������ȥ
//    }
//
//    if (sum + final >= c) {     // �����ѡԪ��֮�ͼ��ϵ�ǰԪ�ؼӵ����һ��Ԫ�ص��ܺʹ��ڵ���c����
//        b[t] = false;    // ��ѡ��ǰԪ��
//        if (Backtrack(t + 1)) return true;  // ��һ��Ԫ��Backtrack�ɹ�����true
//    }
//
//    final += a[t];   // �ӻ�ȥ
//    return false;   // δ�ҵ�
//}
//
//int main() {
//    ifstream inputFile("input.txt");  // �����ļ���Ϊinput.txt
//    ofstream outputFile("output.txt");  // ����ļ���Ϊoutput.txt
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
//    sort(a, a + n);  // �������������
//
//    if (!Backtrack(0))
//        outputFile << "No Solution!" << endl;
//    else {
//        for (int i = 0; i < n; i++) {
//            if (b[i]) outputFile << a[i] << " ";  // �����Ԫ��Ϊtrue�������
//        }
//        outputFile << endl;  // ������У��������
//    }
//
//    inputFile.close();
//    outputFile.close();
//
//    return 0;
//}
