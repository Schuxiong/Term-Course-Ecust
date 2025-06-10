//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//int f[100][100];
//
//int main()
//{
//    FILE* stream;
//    if (freopen_s(&stream, "input3.txt", "r", stdin) != 0)
//    {
//        perror("freopen_s");
//        return 1;
//    }
//
//    int n;
//    cin >> n;
//
//    for (int i = 0; i < n - 1; i++)
//    {
//        for (int j = i + 1; j <= n - 1; j++)
//        {
//            cin >> f[i][j];
//        }
//    }
//
//    for (int k = 2; k < n; k++)
//    {
//        for (int i = 0; i < n - k; i++)
//        {
//            int j = i + k;
//            for (int p = i + 1; p < j; p++)
//            {
//                int tmp = f[i][p] + f[p][j];
//                if (f[i][j] > tmp)
//                    f[i][j] = tmp;
//            }
//        }
//    }
//    if (freopen_s(&stream, "output3.txt", "w", stdout) != 0)
//    {
//        perror("freopen_s");
//        return 1;
//    }
//
//    cout << f[0][n - 1] << endl;
//
//    return 0;
//}
