//#include "iostream"
//#include "algorithm"
//#include "cmath"
//#include "fstream"
//using namespace std;
//#define INF 100000
///*
//求X和圈乘运算组成的值为K的表达式最少需要多少个圈乘运算
//
//  m为X的位数，圈乘运算表达式最大值不超过 L = (9*m)*9 + 9，当m=1时，不超过171
//  m = lg(X+1) 向上取整
//  s[L][4]存储各数字信息
//  s[i][0] 存储i所需最少圈乘运算次数，s[i][1]存储sum(i)，s[i][2]存储max(i)，s[i][3]存储min(i)
//  s[0][0]、s[0][1]、s[0][2]、s[0][3]分别存储X信息
//
//    s[K][0]为结果
//*/
//
//int** s;
//int X, K, L;
//
//void count(int num[], int i)
//{
//    int t;
//    int max = 0;
//    int min = 10;
//    int sum = 0;
//    while (i)
//    {
//        t = i % 10;
//        if (t > max)
//            max = t;
//        if (t < min)
//            min = t;
//        sum += t;
//        i /= 10;
//    }
//    num[1] = sum;
//    num[2] = max;
//    num[3] = min;
//}
//
//void init()
//{
//    int i = 1;
//    int m = ceil(log(X + 1) / log(10.0));
//    L = 81 * m + 9;
//    if (L < 171)
//        L = 171;
//
//    s = new int* [L + 1];
//    for (int i = 0; i <= L; i++)
//        s[i] = new int[4];
//
//    for (i = 1; i <= L; i++)
//    {
//        s[i][0] = INF;  //圈乘运算最少次数
//        s[i][1] = 0;    //sum(i)
//        s[i][2] = 0;    //max(i)
//        s[i][3] = INF;  //min(i)
//    }
//
//    for (i = 1; i <= L; i++)  //计算s[i][4]中的信息
//        count(s[i], i);
//
//    s[0][0] = 0;
//    count(s[0], X);
//}
//
//int dyna()
//{
//    init();
//
//    if (X == K)
//        return 0;
//    if (K > L)
//        return -1;
//
//    bool flag = true;
//    while (flag)  //最优值不再更新时退出
//    {
//        flag = false;
//        for (int i = 0; i <= L; i++)
//        {
//            if (s[i][0] < INF)  //i已计算过
//                for (int j = 0; j <= L; j++)
//                    if (s[j][0] < INF)  //j已计算过
//                    {
//                        int a = s[i][1] * s[j][2] + s[j][3];
//                        if (s[a][0] > s[i][0] + s[j][0] + 1) //圈乘个数更少，更新
//                        {
//                            s[a][0] = s[i][0] + s[j][0] + 1;
//                            flag = true;
//                        }
//                    }
//        }
//    }
//
//    if (s[K][0] < INF)
//        return s[K][0];
//    else
//        return -1;
//}
//
//int main()
//{
//    ifstream inputFile("input4.txt");
//    ofstream outputFile("output4.txt");
//    while (true) {
//        inputFile >> X >> K;
//        if (X == 0 && K == 0) {
//            break;
//        }
//        //  cout << dyna() << endl;
//        outputFile << dyna() << endl;
//    }
//    inputFile.close();
//    outputFile.close();
//    return 0;
//}