//#include<iostream>
//#include<cstdio>
//#include<fstream>
//
//using namespace std;
//
//int n; //数字三角形行数
//int triangle[101][1001]; //数字三角形数组
//int s[101]; //路径数组
//
////读取
//void Read();
////写入
//void Write();
////求解从三角形顶端到底端的路径所经过的数字和的最大值
//void Solution(int n, int triangle[][1001]);
////求解路径数组
//void TrackBack(int n, int triangle[][1001]);
//
//int main()
//{
//    //读取
//    Read();
//    //求解从三角形顶端到底端的路径所经过的数字和的最大值
//    Solution(n, triangle);
//    //写入
//    Write();
//    //输出最优解路径
//    TrackBack(n, triangle);
//    for (int i = 1; i <= n; ++i)
//    {
//        cout << s[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}
//
//void Read()
//{
//    ifstream ifs;
//    //打开输入文件
//    ifs.open("C:\\Users\\74140\\Desktop\\学期课程\\算法设计与分析\\test2\\test2\\input2.txt", ios::in);
//    //读取数据
//    ifs >> n;
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= i; ++j)
//        {
//            ifs >> triangle[i][j];
//        }
//    }
//    //关闭输入文件
//    ifs.close();
//}
//
//void Write()
//{
//    ofstream ofs;
//    //创建输出文件
//    ofs.open("C:\\Users\\74140\\Desktop\\学期课程\\算法设计与分析\\test2\\test2\\output2.txt", ios::out);
//    //写入数据
//    ofs << triangle[1][1] << endl;
//    //关闭输出文件
//    ofs.close();
//}
//
//void Solution(int n, int triangle[][1001])
//{
//    //从下往上计算
//    for (int i = n - 1; i >= 1; --i)
//    {
//        for (int j = 1; j <= i; ++j)
//        {
//            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
//        }
//    }
//}
//
//void TrackBack(int n, int triangle[][1001])
//{
//    //从上往下计算
//    int i, j, maxium;
//    i = j = 1;
//    while (i < n)
//    {
//        if (triangle[i + 1][j] > triangle[i + 1][j + 1])
//        {
//            s[i] = triangle[i][j] - triangle[i + 1][j];
//            i = i + 1;
//            j = j;
//        }
//        else
//        {
//            s[i] = triangle[i][j] - triangle[i + 1][j + 1];
//            i = i + 1;
//            j = j + 1;
//        }
//    }
//    s[i] = triangle[i][j];
//}
