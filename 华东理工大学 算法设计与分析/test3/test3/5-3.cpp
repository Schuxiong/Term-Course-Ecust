//#include <iostream>
//#include <fstream>
//#include <algorithm>
//using namespace std;
//
//int n;
//int boy[21][21], girl[21][21];   // �ֱ����ڴ���С�Ů�˶�Ա�ľ�������
//int Max = INT_MIN;   // Max������Ů˫���������Ƶ��ܺ͵����ֵ
//int sum = 0;   // sumΪ��ʱ���
//int data_array[21][21];   // data_array[i][]���ڴ�����˶�Ա i ��Ժ��˫����������
//int maxSum[21];   // ��¼ÿ������ƥ���ɴﵽ�����˫����������
//int book[21];   // ���ڱ��Ů�˶�Ա�Ƿ���ƥ�䣺book[0]δƥ�䣻book[1]ƥ��
//
//void dfs(int t)
//{
//    if (t >= n)   // t����n֮�󣬴���ȫ����Ƿ�����,�õ������ֵ
//    {
//        Max = max(Max, sum);
//        return;
//    }
//    int ctn = 0;   // ��֦������֮ǰt����ƥ��õ���Ů�˶�Ա��sum��֮��� t->n-1 ����ƥ��Ů�����ֵ���������Ѿ��õ���Max�Ƚϣ���ǰ��<=Max����֦
//    for (int i = t; i < n; i++)   // ��t��t֮������ƥ��Ů�������ֵ�ĺ�
//        ctn += maxSum[i];
//    if (sum + ctn < Max)   // ���ӵ�t��->��n�飬��ǰ����sum���ϼ���ƥ�������ֵcxn����ȻС��Max ������Ҫ��֦�ˣ���MaxΪ�Ѿ���õ����ֵ
//        return;
//    for (int i = 0; i < n; i++)   // ��cxn>=Max��Ҫ̽���������ӵ�t��������ʼƥ�䣬��δƥ���Ů��
//    {
//        if (!book[i])   // �� i ��Ů��δƥ��
//        {
//            book[i] = 1;   // �� t ������ƥ��Ů��i
//            sum += data_array[t][i];   // ��������t��Ů��i����Ů˫����������
//            dfs(t + 1);   // Ϊ��i+1������ƥ��
//            book[i] = 0;   // ���� t ������ƥ��Ů��i�õ���sum������Max�������
//            sum -= data_array[t][i];
//        }
//    }
//}
//
//int main()
//{
//    ifstream inputFile("input.txt");  // �����ļ���Ϊinput.txt
//    ofstream outputFile("output.txt");  // ����ļ���Ϊoutput.txt
//
//    if (!inputFile.is_open()) {
//        cerr << "Error: Unable to open input file!" << endl;
//        return 1;
//    }
//
//    if (!outputFile.is_open()) {
//        cerr << "Error: Unable to open output file!" << endl;
//        inputFile.close();
//        return 1;
//    }
//
//    inputFile >> n;
//
//    for (int i = 0; i < n; i++)   // �������˶�Ա�ľ�������
//    {
//        for (int j = 0; j < n; j++)
//            inputFile >> boy[i][j];
//    }
//
//    for (int i = 0; i < n; i++)   // ����Ů�˶�Ա�ľ�������
//    {
//        for (int j = 0; j < n; j++)
//            inputFile >> girl[i][j];
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            data_array[i][j] = boy[i][j] * girl[j][i];   // ��ÿ������������Ů˫���������ƣ����ܵõ�i*j�ֽ����������P[i][j]*Q[j][i]��Q[i][j]*P[j][i]��
//            maxSum[i] = max(maxSum[i], data_array[i][j]);   // ��¼ÿ������ƥ���ɴﵽ�����˫���������ƣ����ں���ļ�֦
//        }
//    }
//
//    dfs(0);
//
//    outputFile << Max << endl;
//
//    inputFile.close();
//    outputFile.close();
//
//    return 0;
//}
