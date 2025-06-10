//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct Bank {
//    int money;
//    double probability;
//};
//
//bool compareBanks(const Bank& a, const Bank& b) {
//    return a.probability < b.probability;
//}
//
//int maxMoney(vector<Bank>& banks, double limit) {
//    sort(banks.begin(), banks.end(), compareBanks);
//
//    int totalMoney = 0;
//    double currentProbability = 1.0;
//
//    for (const Bank& bank : banks) {
//        currentProbability *= (1.0 - bank.probability);
//
//        if (currentProbability >= limit) {
//            totalMoney += bank.money;
//        }
//        else {
//            break;  // Stop when the probability goes below the limit
//        }
//    }
//
//    return totalMoney;
//}
//
//int main() {
//    int T;
//    cin >> T;
//
//    while (T--) {
//        double limit;
//        int N;
//        cin >> limit >> N;
//
//        vector<Bank> banks(N);
//
//        for (int i = 0; i < N; i++) {
//            cin >> banks[i].money >> banks[i].probability;
//        }
//
//        int result = maxMoney(banks, limit);
//        cout << "result = " << result << endl;
//    }
//
//    return 0;
//}
