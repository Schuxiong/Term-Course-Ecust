//#include <iostream>
//#include <cmath>
//#include <iomanip>
//#include <vector>
//
//using namespace std;
//
//double calculateDistance(pair<double, double> p1, pair<double, double> p2) {
//    double dx = p1.first - p2.first;
//    double dy = p1.second - p2.second;
//    return sqrt(dx * dx + dy * dy);
//}
//
//double findMaxRadius(vector<pair<double, double>>& toys) {
//    double maxRadius = 0.0;
//
//    for (size_t i = 0; i < toys.size(); ++i) {
//        for (size_t j = i + 1; j < toys.size(); ++j) {
//            double distance = calculateDistance(toys[i], toys[j]);
//            maxRadius = max(maxRadius, distance / 2);
//        }
//    }
//
//    return maxRadius;
//}
//
//int main() {
//    int N;
//    while (cin >> N && N != 0) {
//        vector<pair<double, double>> toys(N);
//
//        for (int i = 0; i < N; ++i) {
//            cin >> toys[i].first >> toys[i].second;
//        }
//
//        double maxRadius = findMaxRadius(toys);
//
//        cout << fixed << setprecision(2) << maxRadius << endl;
//    }
//
//    return 0;
//}
