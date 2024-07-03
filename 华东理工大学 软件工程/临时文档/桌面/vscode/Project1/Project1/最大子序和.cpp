//最大子序和

//#include <stdio.h>
//#include <iostream>
//using namespace std;
//const int INF = 0x7fffffff;
//int main()
//{
//	int t;             //测试用例个数
//	cin >> t;
//	for (int i = 1; i <= t; i++)
//	{
//		int n;
//		cin >> n;
//		int maxsum = -INF;
//		int start = 1, end = 1, p = 1;  //起点，终点，扫描位置
//		int sum = 0;                    //子序和
//		for (int j = 1; j <= n; j++)
//		{
//			int a; cin >> a; sum += a;  //读入一个元素，累加
//			if (sum > maxsum)
//			{
//				maxsum = sum;
//				start = p;
//				end = j;
//			}
//			if (sum < 0)     //扫描到j时，若前面最大子序和为负数，从下一个重新开始 
//			{
//				sum = 0;
//				p = j + 1;
//			}
//		}
//		printf("Case %d:\n", i);
//		printf("%d %d %d\n", maxsum, start, end);
//
//	}
//	return 0;

/*
#include <stdio.h>
#include <iostream>
using namespace std;
int dp[100005];         //dp[i]，以第i个数结尾的最大值
int main()
{
	int t; cin >> t;
	for (int k = 1; k <= t; k++)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> dp[i]; //用dp[]存储数据
		int start = 1, end = 1,p = 1;
		int maxsum = dp[1];
		for (int i = 2; i <= n; i++)
		{
			if (dp[i - 1] + dp[i] >= dp[i])      //转移方程
				dp[i] = dp[i - 1] + dp[i];
			else p = i;
			if (dp[i] > maxsum)
			{
				maxsum = dp[i]; start = p; end = i;
			}
		}
		printf("Case %d:\n", k);
		printf("%d %d %d\n", maxsum, start, end);
		if (k != t) cout << endl;
	}
}