//#include<iostream>
//#include<cstdio>
//#include<fstream>
//
//using namespace std;
//
//int n; //��������������
//int triangle[101][1001]; //��������������
//int s[101]; //·������
//
////��ȡ
//void Read();
////д��
//void Write();
////���������ζ��˵��׶˵�·�������������ֺ͵����ֵ
//void Solution(int n, int triangle[][1001]);
////���·������
//void TrackBack(int n, int triangle[][1001]);
//
//int main()
//{
//    //��ȡ
//    Read();
//    //���������ζ��˵��׶˵�·�������������ֺ͵����ֵ
//    Solution(n, triangle);
//    //д��
//    Write();
//    //������Ž�·��
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
//    //�������ļ�
//    ifs.open("C:\\Users\\74140\\Desktop\\ѧ�ڿγ�\\�㷨��������\\test2\\test2\\input2.txt", ios::in);
//    //��ȡ����
//    ifs >> n;
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= i; ++j)
//        {
//            ifs >> triangle[i][j];
//        }
//    }
//    //�ر������ļ�
//    ifs.close();
//}
//
//void Write()
//{
//    ofstream ofs;
//    //��������ļ�
//    ofs.open("C:\\Users\\74140\\Desktop\\ѧ�ڿγ�\\�㷨��������\\test2\\test2\\output2.txt", ios::out);
//    //д������
//    ofs << triangle[1][1] << endl;
//    //�ر�����ļ�
//    ofs.close();
//}
//
//void Solution(int n, int triangle[][1001])
//{
//    //�������ϼ���
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
//    //�������¼���
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
