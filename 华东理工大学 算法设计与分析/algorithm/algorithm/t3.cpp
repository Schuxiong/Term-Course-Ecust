//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//int dfs(char* s, int l, int r, int k)
//{
//	int cnt[26];
//	memset(cnt, 0, sizeof(cnt));
//	for (int i = l; i <= r; i++) // �������У�Ӧ�� l ��ʼ������ 1
//	{
//		cnt[s[i] - 'a']++;
//	}
//
//	char split = 0;
//	for (int i = 0; i < 26; i++)
//	{
//		if (cnt[i] > 0 && cnt[i] < k)
//		{
//			split = i + 'a';
//			break;
//		}
//	}
//	if (split == 0)
//	{
//		return r - l + 1;
//	}
//
//	int i = l; // �������У�Ӧ�� l ��ʼ������ 1
//	int ret = 0;
//	while (i <= r)
//	{
//		while (i <= r && s[i] == split) { // �������У�����ֵ�Ÿ�Ϊ��Ⱥ�
//			i++;
//		}
//		if (i > r) {
//			break;
//		}
//		int start = i;
//		while (i <= r && s[i] != split) {
//			i++;
//		}
//		int length = dfs(s, start, i - 1, k);
//		ret = fmax(ret, length);
//	}
//	return ret;
//}
//
//int longestSubstring(char* s, int k) {
//	return dfs(s, 0, strlen(s) - 1, k);
//}
//
//int main() {
//	// ����������Ҫ���������
//	char s[] = "ababbc";
//	int k = 2;
//	// ��������ַ�������
//	int result = longestSubstring(s, k);
//	// ������
//	printf("����ַ������ȣ�%d\n", result);
//	getchar();
//	return 0;
//}
