//#include <stdio.h>
//#include <string.h>
//
//void dfs(char* str, int s, int e, char* res, int* max) {
//    if (s >= e) return;
//    bool f = true;  // 修正此行，将 future 改为 true
//    int i;
//    for (i = s; i <= e; i++) {  // 修正此行，将 = 改为 <=
//        char* pos = strchr(str + s, str[i] <= 'Z' ? str[i] + 32 : str[i] - 32);
//        if (!(pos && pos <= str + e)) {
//            f = false;
//            break;
//        }
//    }
//    if (!f) {
//        dfs(str, s, i - 1, res, max);
//        dfs(str, i + 1, e, res, max);
//    }
//    else {
//        if (e - s + 1 > *max) {
//            *max = e - s + 1;
//            for (int j = s; j <= e; j++) {  // 修正此行，将 i 改为 j
//                res[j - s] = str[j];
//            }
//        }
//    }
//}
//
//int main() {
//    //在此编辑输入
//    char str[] = "YazaAay";
//    int len = strlen(str);
//    char res[100];
//    int max_len = 0;
//
//    dfs(str, 0, len - 1, res, &max_len);
//
//    printf("Longest alternating case substring: %.*s\n", max_len, res);
//    getchar();
//    return 0;
//}
