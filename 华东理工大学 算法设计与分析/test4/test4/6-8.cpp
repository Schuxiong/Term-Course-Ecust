#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n, k, a[20], b[20], min_t = 2100000000;

void input_data(FILE* file)
{
    fscanf(file, "%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        fscanf(file, "%d", &a[i]);
    for (int i = 1; i <= k; i++) // һ��ʼ���еĻ�����û�л���ʱ��
        b[i] = 0;
}

void sear_ch(int x) // Ϊ��x�������������
{
    if (x == n + 1) // �������ȫ����������
    {
        int max_t = b[1]; // �ҵ����л����л���ʱ����Ļ�������Ϊ��η������õ�ʱ��
        for (int i = 2; i <= k; i++)
            if (b[i] > max_t)
                max_t = b[i];
        if (max_t < min_t) // ����ܹ�������Сֵ �͸���
            min_t = max_t;
        return; // �˳���һ��ݹ�
    }
    for (int i = 1; i <= k; i++) // ö��k̨����
    {
        if (b[i] + a[x] > min_t)
            continue; // �����̨�����ټ�����������ȵ�ǰ����Сֵ���û�б�Ҫ����
        b[i] += a[x]; // ��į���������x������
        sear_ch(x + 1); // ����������һ������
        b[i] -= a[x]; // ����
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
