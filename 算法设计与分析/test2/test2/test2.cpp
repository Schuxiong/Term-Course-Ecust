//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Bank {
//    int millions;
//    float probability;
//};
//
//bool compareBanks(const Bank& bank1, const Bank& bank2) {
//    return bank1.probability < bank2.probability;
//}
//
//int main() {
//    int T;
//    cin >> T;
//
//    while (T--) {
//        float P;
//        int N;
//        cin >> P >> N;
//
//        vector<Bank> banks(N);
//        for (int i = 0; i < N; ++i) {
//            cin >> banks[i].millions >> banks[i].probability;
//        }
//
//        // Sort banks by probability in ascending order
//        sort(banks.begin(), banks.end(), compareBanks);
//
//        float totalProbability = 0.0;
//        long long totalMillions = 0;
//        int index = 0;
//
//        // Greedily choose banks until the total probability exceeds the limit
//        while (index < N && totalProbability + banks[index].probability <= P) {
//            totalProbability += banks[index].probability;
//            totalMillions += banks[index].millions;
//            ++index;
//        }
//
//        cout << totalMillions << endl;
//    }
//
//    return 0;
//}
