//��������

//#include <stdio.h>
//#include <iostream>
//using namespace std;
//const int INF = 0x7fffffff;
//int main()
//{
//	int t;             //������������
//	cin >> t;
//	for (int i = 1; i <= t; i++)
//	{
//		int n;
//		cin >> n;
//		int maxsum = -INF;
//		int start = 1, end = 1, p = 1;  //��㣬�յ㣬ɨ��λ��
//		int sum = 0;                    //�����
//		for (int j = 1; j <= n; j++)
//		{
//			int a; cin >> a; sum += a;  //����һ��Ԫ�أ��ۼ�
//			if (sum > maxsum)
//			{
//				maxsum = sum;
//				start = p;
//				end = j;
//			}
//			if (sum < 0)     //ɨ�赽jʱ����ǰ����������Ϊ����������һ�����¿�ʼ 
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
int dp[100005];         //dp[i]���Ե�i������β�����ֵ
int main()
{
	int t; cin >> t;
	for (int k = 1; k <= t; k++)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> dp[i]; //��dp[]�洢����
		int start = 1, end = 1,p = 1;
		int maxsum = dp[1];
		for (int i = 2; i <= n; i++)
		{
			if (dp[i - 1] + dp[i] >= dp[i])      //ת�Ʒ���
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