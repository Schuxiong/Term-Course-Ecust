//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n;
//    while (cin >> n && n) {
//        int all = n * (n - 1) / 2;
//        vector<int> sum(all);
//
//        for (int i = 0; i < all; ++i) {
//            cin >> sum[i];
//        }
//
//        for (int k = 2; k < all; ++k) {
//            vector<int> num(n + 5, 0);
//            vector<bool> vis(all, false);
//
//            if ((sum[0] + sum[1] - sum[k]) % 2 || (sum[0] + sum[1] - sum[k] <= 0))
//                continue;
//
//            num[0] = (sum[0] + sum[1] - sum[k]) / 2;
//            num[1] = (sum[0] - num[0]);
//            num[2] = (sum[1] - num[0]);
//            vis[0] = vis[1] = vis[k] = true;
//
//            int know = 2;
//            bool flag = true;
//
//            while (know != n - 1) {
//                int in = -1;
//                for (int i = 0; i < all; ++i) {
//                    if (vis[i] == false) {
//                        in = sum[i];
//                        vis[i] = true;
//                        break;
//                    }
//                }
//
//                num[++know] = in - num[0];
//
//                for (int i = 1; i < know; ++i) {
//                    int he = num[know] + num[i];
//                    flag = false;
//
//                    for (int j = 0; j < all; ++j) {
//                        if (vis[j] == false && sum[j] == he) {
//                            vis[j] = true;
//                            flag = true;
//                            break;
//                        }
//                    }
//
//                    if (flag == false) break;
//                }
//
//                if (flag == false) break;
//            }
//
//            if (know != n - 1) continue;
//
//            for (int i = 0; i < n; ++i) {
//                cout << num[i] << ' ';
//            }
//            cout << endl;
//            break;
//        }
//    }
//
//    return 0;
//}
