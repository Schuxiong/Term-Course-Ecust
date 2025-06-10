//#include <iostream>
//#include <fstream>
//#include <algorithm>
//using namespace std;
//
//int n;
//int boy[21][21], girl[21][21];   // 分别用于存放男、女运动员的竞赛优势
//int Max = INT_MIN;   // Max代表男女双方竞赛优势的总和的最大值
//int sum = 0;   // sum为临时求和
//int data_array[21][21];   // data_array[i][]用于存放男运动员 i 配对后的双方竞赛优势
//int maxSum[21];   // 记录每个男生匹配后可达到的最大双方竞赛优势
//int book[21];   // 用于标记女运动员是否已匹配：book[0]未匹配；book[1]匹配
//
//void dfs(int t)
//{
//    if (t >= n)   // t到达n之后，代表全部标记访问了,得到了最大值
//    {
//        Max = max(Max, sum);
//        return;
//    }
//    int ctn = 0;   // 剪枝函数：之前t个已匹配好的男女运动员的sum与之后的 t->n-1 个男匹配女的最大值加起来与已经得到的Max比较，若前者<=Max，剪枝
//    for (int i = t; i < n; i++)   // 求t及t之后男生匹配女生的最大值的和
//        ctn += maxSum[i];
//    if (sum + ctn < Max)   // 若从第t组->第n组，当前搜索sum加上假设匹配后的最大值cxn，仍然小于Max ，就需要剪枝了，则Max为已经求得的最大值
//        return;
//    for (int i = 0; i < n; i++)   // 若cxn>=Max，要探索子树。从第t个男生开始匹配，找未匹配的女生
//    {
//        if (!book[i])   // 第 i 个女生未匹配
//        {
//            book[i] = 1;   // 第 t 个男生匹配女生i
//            sum += data_array[t][i];   // 加上男生t与女生i的男女双方竞赛优势
//            dfs(t + 1);   // 为第i+1个男生匹配
//            book[i] = 0;   // 若第 t 个男生匹配女生i得到的sum不大于Max，则回溯
//            sum -= data_array[t][i];
//        }
//    }
//}
//
//int main()
//{
//    ifstream inputFile("input.txt");  // 输入文件名为input.txt
//    ofstream outputFile("output.txt");  // 输出文件名为output.txt
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
//    for (int i = 0; i < n; i++)   // 输入男运动员的竞赛优势
//    {
//        for (int j = 0; j < n; j++)
//            inputFile >> boy[i][j];
//    }
//
//    for (int i = 0; i < n; i++)   // 输入女运动员的竞赛优势
//    {
//        for (int j = 0; j < n; j++)
//            inputFile >> girl[i][j];
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            data_array[i][j] = boy[i][j] * girl[j][i];   // 对每个男生都求男女双方竞赛优势，则能得到i*j种结果（涵盖了P[i][j]*Q[j][i]与Q[i][j]*P[j][i]）
//            maxSum[i] = max(maxSum[i], data_array[i][j]);   // 记录每个男生匹配后可达到的最大双方竞赛优势，用于后面的剪枝
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
