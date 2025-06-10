//#include<iostream>
//#include<stdio.h>
//#include<fstream>
//#define MAXN 1005
//#include<stdlib.h>
//#include<limits.h>
//
//int a[MAXN];  // ����ÿ��������A�����ϵ�ִ��ʱ��
//int b[MAXN];  // ����ÿ��������B�����ϵ�ִ��ʱ��
//
//int f[MAXN][MAXN];  // ��̬�滮��f[i][j]��ʾ��A���ǰi�����������£���ִ��ʱ�䲻����j����С��ʱ��
//int n;  // ��������
//
//using namespace std;
//
//// ����������Ⱥ�����������̨�����������������ʱ��
//int task_schedule(int* a, int* b, int n)
//{
//    int sumA = a[1];  // ��ʼʱ��A��������ִ��ʱ��Ϊ��һ�������ִ��ʱ��
//
//    // ����ֻ��һ������������k=1��
//    for (int x = 0; x < a[1]; x++)
//    {
//        f[1][x] = b[1];
//    }
//    f[1][a[1]] = (a[1] < b[1]) ? 0 : b[1];
//
//    // ��ʼ����̬�滮��
//    for (int i = 2; i <= n; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            f[i][j] = INT_MAX;  // ��A��ɵ�i�������ʱ�䲻����j�������B�����������ʱ��
//        }
//    }
//
//    // ��ʼ��̬�滮
//    for (int k = 2; k <= n; k++)
//    {
//        sumA += a[k];  // ����A��������ִ��ʱ��
//
//        for (int x = 0; x <= sumA; x++)
//        {
//            if (x < a[k])  // �޶����ʱ��С����ɵ�k�������ʱ�䣬ֻ����Bִ�е�k������
//            {
//                f[k][x] = f[k - 1][x] + b[k];
//            }
//            else
//            {
//                // �Ƚϵ�k��������A��ɺ�B���B���ѵ����ʱ��
//                f[k][x] = (f[k - 1][x] + b[k] < f[k - 1][x - a[k]]) ? f[k - 1][x] + b[k] : f[k - 1][x - a[k]];
//            }
//        }
//    }
//
//    // Ѱ�������ʱ��
//    int min = INT_MAX;
//    for (int i = 0; i <= sumA; i++)
//    {
//        int temp = (f[n][i] > i) ? f[n][i] : i;  // ѡ��������һ������ʱͣ��ʱ��������Ǹ�
//        if (temp < min)
//        {
//            min = temp;  // ѡ����ô���ͣ��ʱ��������������ʱ����Ϊ��̨���������������ʱ��
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
//    // ��ȡ��������
//    in >> n;
//
//    // ��̬�����ڴ汣��������A��B�ϵ�ִ��ʱ��
//    int* a = new int[n];
//    int* b = new int[n];
//
//    // ��ȡ����ִ��ʱ��
//    for (int i = 1; i <= n; i++)
//    {
//        in >> a[i];
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        in >> b[i];
//    }
//
//    // ����������Ⱥ�����ȡ�����ʱ��
//    int min_time = task_schedule(a, b, n);
//
//    // ���������ļ��Ϳ���̨
//    out << min_time << endl;
//    cout << min_time << endl;
//
//    // �ر��ļ���
//    in.close();
//    out.close();
//}
