#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n, k, a[20], b[20], min_t = 2100000000;

void input_data(FILE* file)
{
    fscanf(file, "%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        fscanf(file, "%d", &a[i]);
    for (int i = 1; i <= k; i++) // 一开始所有的机器都没有花费时间
        b[i] = 0;
}

void sear_ch(int x) // 为第x件工作分配机器
{
    if (x == n + 1) // 如果工作全都分配完了
    {
        int max_t = b[1]; // 找到所有机器中花费时间最长的机器，即为这次分配所用的时间
        for (int i = 2; i <= k; i++)
            if (b[i] > max_t)
                max_t = b[i];
        if (max_t < min_t) // 如果能够更新最小值 就更新
            min_t = max_t;
        return; // 退出这一层递归
    }
    for (int i = 1; i <= k; i++) // 枚举k台机器
    {
        if (b[i] + a[x] > min_t)
            continue; // 如果这台机器再加上这件任务会比当前的最小值大就没有必要加了
        b[i] += a[x]; // 第i台机器分配第x件任务
        sear_ch(x + 1); // 继续分配下一件任务
        b[i] -= a[x]; // 回溯
    }
}

void get_ans()
{
    sear_ch(1);
}

void output_ans(FILE* file)
{
    fprintf(file, "%d\n", min_t);
}

int main()
{
    FILE* inFile = fopen("input.txt", "r");
    FILE* outFile = fopen("output.txt", "w");

    if (!inFile || !outFile)
    {
        printf("Error opening files.\n");
        return 1;
    }

    input_data(inFile);
    get_ans();
    output_ans(outFile);

    fclose(inFile);
    fclose(outFile);

    return 0;
}
