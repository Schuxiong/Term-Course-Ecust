#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%6d",a[i]);
    printf("\n");
}
//快速排序
void QuickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int i = left, j = right, x = a[left];
        while (i < j)
        {
            while(i < j && a[j] >= x) // 从右向左找第一个小于x的数
                j--;  
            if(i < j) 
                a[i++] = a[j];

            while(i < j && a[i] < x) // 从左向右找第一个大于等于x的数
                i++;  
            if(i < j) 
                a[j--] = a[i];
        }
        a[i] = x;
        QuickSort(a, left, i - 1); // 递归调用 
        QuickSort(a, i + 1, right);
    }
}



int main()
{
    int array[10000];
    int len ;
    int ch;
    int N;
    while(1)
    {
        scanf("%d",&N);
        len =N;
        for(int i=0;i<N;i++)
        {
        	scanf("%d",&array[i]);
		}
		
         QuickSort(array,0,len-1);
            printf("排序结果为:\n");
            print(array,len);
        system("pause");
        system("cls");
    }
}

