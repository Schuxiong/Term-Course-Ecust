//#include <iostream>
//
//using namespace std;
//
//int calculateF(int A, int B, int n) {
//    if (n == 1 || n == 2) {
//        return 1;
//    }
//
//    int f_n_minus_1 = 1;
//    int f_n_minus_2 = 1;
//    int f_n;
//
//    for (int i = 3; i <= n; ++i) {
//        f_n = (A * f_n_minus_1 + B * f_n_minus_2) % 7;
//        f_n_minus_2 = f_n_minus_1;
//        f_n_minus_1 = f_n;
//    }
//
//    return f_n;
//}
//
//int main() {
//    int A, B, n;
//
//    while (cin >> A >> B >> n && !(A == 0 && B == 0 && n == 0)) {
//        int result = calculateF(A, B, n);
//        cout << result << endl;
//    }
//
//    return 0;
//}
