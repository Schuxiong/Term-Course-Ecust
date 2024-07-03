//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//int dfs(char* s, int l, int r, int k)
//{
//	int cnt[26];
//	memset(cnt, 0, sizeof(cnt));
//	for (int i = l; i <= r; i++) // 修正此行，应从 l 开始而不是 1
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
//	int i = l; // 修正此行，应从 l 开始而不是 1
//	int ret = 0;
//	while (i <= r)
//	{
//		while (i <= r && s[i] == split) { // 修正此行，将赋值号改为相等号
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
//	// 在这里输入要处理的数组
//	char s[] = "ababbc";
//	int k = 2;
//	// 计算最长子字符串长度
//	int result = longestSubstring(s, k);
//	// 输出结果
//	printf("最长子字符串长度：%d\n", result);
//	getchar();
//	return 0;
//}
