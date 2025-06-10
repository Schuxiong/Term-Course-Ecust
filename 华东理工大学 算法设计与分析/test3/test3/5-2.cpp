//#include <iostream>
//#include<fstream>
//#include <vector>
//using namespace std;
//
//int n, m;
//int bestx[10];// 这是最终的最优解排列顺序
//int B[10][10];//电路板在连接块中的排列，是一个二维数组
//int x[10], low[10], high[10];// 分别是当前的排列、最左边电路板、最右边电路板
//int bestd = 0;// 最优解
//
//int len(int ii) {// 计算当前ii排列最小长度
//	for (int i = 1; i <= m; i++) {
//		high[i] = 0;
//		low[i] = n + 1;// 先初始化最左边和最右边的值，
//	}
//	for (int i = 1; i <= ii; i++)// 对于第i行
//		for (int k = 1; k <= m; k++)// k列
//			if (B[x[i]][k] > 0) {// 如果第i个电路板在第k个连接块中，
//				if (i < low[k])//low[k]代表第K个连接块的最左边的值，如果i比它小，则更新左值
//					low[k] = i;
//				if (i > high[k])
//					high[k] = i;//如果比初始的右值大，则更新右值
//			}
//	int tmp = 0;
//	for (int k = 1; k <= m; k++)
//		if (low[k] <= n && high[k] > 0 && tmp < high[k] - low[k])
//			tmp = high[k] - low[k];//计算每个连接块的举例
//	return tmp;
//}
//void swap(int* x, int i, int j) {// 交换i和j位置的值
//	int tmp;
//	tmp = x[i];
//	x[i] = x[j];
//	x[j] = tmp;
//}
//void backtrack(int i) {
//	if (i == n) {// 如果到达末尾
//		int tmp = len(i);// 计算当前排列最小长度
//		if (tmp < bestd) {
//			bestd = tmp;
//			for (int j = 1; j <= n; j++)
//				bestx[j] = x[j];
//		} // 如果比最优解还要好，则更新bestx[]排列；
//	}
//	else {// 若不是末尾；
//		for (int j = i; j <= n; j++) {
//			swap(x, i, j);
//			int ld = len(i);
//			if (ld < bestd)
//				backtrack(i + 1);// 则继续进入下一个数，
//			swap(x, i, j);
//		}
//	}
//}
//
//int arrangeBoards() {
//	bestd = n + 1;// 先假设一个很大的值
//	for (int i = 1; i <= n; i++)
//		x[i] = i;// 这里是最开始的排序；
//	backtrack(1);
//	return bestd;
//}
//
//int main(void) {
//	ifstream ifs("input.txt");//文件输入流
//	ifs >> n;
//	ifs >> m;
//
//	vector<int> temp(m);
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			ifs >> B[i][j];// 输入的电路板的二维数组排列
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
