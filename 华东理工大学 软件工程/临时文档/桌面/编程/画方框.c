#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int id;
        scanf("%6d", &id);
        scanf("%4d", &id); printf("%04d", id);
        scanf("%2d", &id); printf("-%02d", id);
        scanf("%2d", &id); printf("-%02d\n", id);
        char aa[20];
        scanf("%s", &aa);
    }
    return 0;
}