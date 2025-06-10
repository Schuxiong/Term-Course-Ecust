//#include<iostream>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//
//int flag;
//int fuck;
//int maxx;
//int minn;
//int f[101];
//
//int dfs(int t)
//{
//	if (t == 1)
//	{
//		if (flag == 0)
//		{
//			fuck = 1;
//			flag = 1;
//			if (dfs(maxx)) return 1;
//			else
//			{
//				flag = 0;
//				return 0;
//			}
//		}
//		return 1;
//	}
//	int len = 100 < t ? 100 : t;
//	for (int i = 2; i <= len; i++)
//	{
//		if (t % i == 0 && f[i] == 0)
//		{
//			f[i] = 1;
//			if (dfs(t / i)) return 1;
//			f[i] = 0;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int x, y;
//	while (scanf_s("%d%d", &x, &y) != EOF)
//	{
//		int ans;
//		flag = 0;
//		fuck = 0;
//		maxx = max(x, y);
//		minn = min(x, y);
//		memset(f, 0, sizeof(f));
//		int tt = dfs(minn);
//		if (fuck == 0) ans = maxx;
//		else if (fuck == 1 && tt == 1) ans = maxx;
//		else ans = minn;
//		printf("%d\n", ans);
//	}
//	return 0;
//}
