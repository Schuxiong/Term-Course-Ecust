//#include <iostream>
//using namespace std;
//
//const int MOD = 1000000007;
//
//long long power(long long base, long long exponent) {
//    long long result = 1;
//    while (exponent > 0) {
//        if (exponent % 2 == 1) {
//            result = (result * base) % MOD;
//        }
//        base = (base * base) % MOD;
//        exponent /= 2;
//    }
//    return result;
//}
//
//long long countWays(int N, int M, int K) {
//    long long result = 0;
//
//    // Calculate ways for Garrison members
//    result += power(M + 1, N - K);
//
//    // Subtract ways for Recon Corp members
//    for (int i = 1; i <= K; i++) {
//        result = (result - power(i + 1, N - i) + MOD) % MOD;
//    }
//
//    return MOD-result+1;
//}
//
//int main() {
//
//    int T = 2;
//
//    while (T--) {
//        int N, M, K;
//        cin >> N >> M >> K;
//
//        long long  ways = countWays(N, M, K);
//        cout << ways << endl;
//    }
//
//    return 0;
//}
