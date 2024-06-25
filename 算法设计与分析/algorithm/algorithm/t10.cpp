//#include <iostream>
//#include <algorithm>
//#include <iomanip> // Add this line
//#include <vector>
//
//using namespace std;
//
//int gcd(int a, int b) {
//    if (b == 0) {
//        return a;
//    }
//    return gcd(b, a % b);
//}
//
//int main() {
//    int STEP, MOD;
//
//    while (cin >> STEP >> MOD) {
//        int greatestCommonDivisor = gcd(STEP, MOD);
//
//        cout << right << setw(10) << STEP << right << setw(10) << MOD;
//
//        if (greatestCommonDivisor == 1) {
//            cout << " Good Choice" << endl;
//        }
//        else {
//            cout << "    Bad Choice" << endl;
//        }
//
//        cout << endl;
//    }
//
//    return 0;
//}
