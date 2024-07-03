//#include<iostream>
//#include<stdio.h>
//#include<fstream>
//#define MAXN 1005
//#include<stdlib.h>
//#include<limits.h>
//
//int a[MAXN];  // 保存每个任务在A机器上的执行时间
//int b[MAXN];  // 保存每个任务在B机器上的执行时间
//
//int f[MAXN][MAXN];  // 动态规划表，f[i][j]表示在A完成前i个任务的情况下，总执行时间不超过j的最小总时间
//int n;  // 任务数量
//
//using namespace std;
//
//// 定义任务调度函数，返回两台机器完成任务的最短总时间
//int task_schedule(int* a, int* b, int n)
//{
//    int sumA = a[1];  // 初始时，A机器的总执行时间为第一个任务的执行时间
//
//    // 处理只有一件任务的情况（k=1）
//    for (int x = 0; x < a[1]; x++)
//    {
//        f[1][x] = b[1];
//    }
//    f[1][a[1]] = (a[1] < b[1]) ? 0 : b[1];
//
//    // 初始化动态规划表
//    for (int i = 2; i <= n; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            f[i][j] = INT_MAX;  // 在A完成第i个任务的时间不超过j的情况下B完成任务的最短时间
//        }
//    }
//
//    // 开始动态规划
//    for (int k = 2; k <= n; k++)
//    {
//        sumA += a[k];  // 更新A机器的总执行时间
//
//        for (int x = 0; x <= sumA; x++)
//        {
//            if (x < a[k])  // 限定完成时间小于完成第k个任务的时间，只能由B执行第k个任务
//            {
//                f[k][x] = f[k - 1][x] + b[k];
//            }
//            else
//            {
//                // 比较第k个任务由A完成和B完成B花费的最短时间
//                f[k][x] = (f[k - 1][x] + b[k] < f[k - 1][x - a[k]]) ? f[k - 1][x] + b[k] : f[k - 1][x - a[k]];
//            }
//        }
//    }
//
//    // 寻找最短总时间
//    int min = INT_MAX;
//    for (int i = 0; i <= sumA; i++)
//    {
//        int temp = (f[n][i] > i) ? f[n][i] : i;  // 选择完成最后一个任务时停机时间最晚的那个
//        if (temp < min)
//        {
//            min = temp;  // 选择这么多个停机时间最晚里面的最短时间作为两台机器完成任务的最短时间
//        }
//    }
//    return min;
//}
//
//int main() {
//    int n;
//    ifstream in("input.txt");
//    ofstream out("output.txt");
//
//    // 读取任务数量
//    in >> n;
//
//    // 动态分配内存保存任务在A和B上的执行时间
//    int* a = new int[n];
//    int* b = new int[n];
//
//    // 读取任务执行时间
//    for (int i = 1; i <= n; i++)
//    {
//        in >> a[i];
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        in >> b[i];
//    }
//
//    // 调用任务调度函数获取最短总时间
//    int min_time = task_schedule(a, b, n);
//
//    // 输出结果到文件和控制台
//    out << min_time << endl;
//    cout << min_time << endl;
//
//    // 关闭文件流
//    in.close();
//    out.close();
//}
