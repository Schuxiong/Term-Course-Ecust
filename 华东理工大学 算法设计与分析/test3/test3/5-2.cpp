//#include <iostream>
//#include<fstream>
//#include <vector>
//using namespace std;
//
//int n, m;
//int bestx[10];// �������յ����Ž�����˳��
//int B[10][10];//��·�������ӿ��е����У���һ����ά����
//int x[10], low[10], high[10];// �ֱ��ǵ�ǰ�����С�����ߵ�·�塢���ұߵ�·��
//int bestd = 0;// ���Ž�
//
//int len(int ii) {// ���㵱ǰii������С����
//	for (int i = 1; i <= m; i++) {
//		high[i] = 0;
//		low[i] = n + 1;// �ȳ�ʼ������ߺ����ұߵ�ֵ��
//	}
//	for (int i = 1; i <= ii; i++)// ���ڵ�i��
//		for (int k = 1; k <= m; k++)// k��
//			if (B[x[i]][k] > 0) {// �����i����·���ڵ�k�����ӿ��У�
//				if (i < low[k])//low[k]�����K�����ӿ������ߵ�ֵ�����i����С���������ֵ
//					low[k] = i;
//				if (i > high[k])
//					high[k] = i;//����ȳ�ʼ����ֵ���������ֵ
//			}
//	int tmp = 0;
//	for (int k = 1; k <= m; k++)
//		if (low[k] <= n && high[k] > 0 && tmp < high[k] - low[k])
//			tmp = high[k] - low[k];//����ÿ�����ӿ�ľ���
//	return tmp;
//}
//void swap(int* x, int i, int j) {// ����i��jλ�õ�ֵ
//	int tmp;
//	tmp = x[i];
//	x[i] = x[j];
//	x[j] = tmp;
//}
//void backtrack(int i) {
//	if (i == n) {// �������ĩβ
//		int tmp = len(i);// ���㵱ǰ������С����
//		if (tmp < bestd) {
//			bestd = tmp;
//			for (int j = 1; j <= n; j++)
//				bestx[j] = x[j];
//		} // ��������Ž⻹Ҫ�ã������bestx[]���У�
//	}
//	else {// ������ĩβ��
//		for (int j = i; j <= n; j++) {
//			swap(x, i, j);
//			int ld = len(i);
//			if (ld < bestd)
//				backtrack(i + 1);// �����������һ������
//			swap(x, i, j);
//		}
//	}
//}
//
//int arrangeBoards() {
//	bestd = n + 1;// �ȼ���һ���ܴ��ֵ
//	for (int i = 1; i <= n; i++)
//		x[i] = i;// �������ʼ������
//	backtrack(1);
//	return bestd;
//}
//
//int main(void) {
//	ifstream ifs("input.txt");//�ļ�������
//	ifs >> n;
//	ifs >> m;
//
//	vector<int> temp(m);
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			ifs >> B[i][j];// ����ĵ�·��Ķ�ά��������
//		}
//	}
//	int minLen = arrangeBoards();
//	cout << minLen << endl;
//	for (int i = 1; i <= n; i++)
//		cout << bestx[i] << " ";
//	getchar();
//	ifs.close();
//	return 0;
//}
