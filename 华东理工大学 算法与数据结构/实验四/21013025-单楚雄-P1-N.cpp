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

void Swap (int *a,int *b)
{
	int t=*a;*a=*b;*b=t;
}

void PercDown(int A[], int p, int N)
{
	int Parent, Child;
	int X;
	
	X = A[p];
	for (Parent = p; (Parent * 2 + 1) < N; Parent = Child)
	{
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (A[Child] < A[Child + 1]))
			Child++;
		if (X >= A[Child])
			break;
		else
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

//堆排序
void HeapSort(int A[], int N)
{
	int i,temp;
	//建立最大堆
	for (i = N / 2 - 1; i >= 0; i--) PercDown(A, i, N);
	//清理堆顶
	for (i = N - 1; i >= 0; i--)
	{
		Swap(&A[0],&A[i]);
		PercDown(A,0,i);
	}
}
//冒泡排序
void BubleSort(int a[],int n)
{
    int i,j,x;
    for(i=0;i<n;i++)   
    {
        for(j=1;j<n-i;j++) 
        {
            if(a[j-1]>a[j]) 
            {
                x=a[j];
                a[j]=a[j-1];
                a[j-1]=x;
            }
        }
    }
}


// 希尔排序
void ShellSort(int A[], int N)
{
	int Si, D, P, i;
	int Tmp;
		//希尔排序 用Sedgewick增量序列，这里只给出部分增量  
		int Sedgewick[] = { 929,505,209,109,41,19,5,1,0 };

	for (Si = 0; Sedgewick[Si] >= N; Si++);//初始的Sedgewick增量不能超过待排序序列长度

	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
		for (P = D; P < N; P++)
		{
			Tmp = A[P];
			for (i =P; i >= D && A[i - D] > Tmp; i -=D)
				A[i] = A[i - D];
			A[i] = Tmp;
		}
}

//插入排序
void InsertSort(int arr[], int n)
{
    int i,j,temp;
    for (i = 1; i < n; i++)    
    {   
        temp=arr[i];
        j=i;
        while(j>0 && arr[j-1]>temp)
            {
                arr[j] = arr[j-1];
                j--;
            }
        arr[j]=temp;
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
        printf("选择排序方法:\n");//显示菜单
        printf("\t0 退出\n\t1 堆排序\n\t2 冒泡排序\n\t3 直接插入排序\n\t4 希尔排序\n你选择>>");
        scanf("%d",&ch);
        scanf("%d",&N);
        len =N;
        for(int i=0;i<N;i++)
        {
        	scanf("%d",&array[i]);
		}
         
        switch(ch)
        {
        case 0:
            return 0;
        case 1:
            HeapSort(array,len);
            printf("堆排序结果:\n");
            print(array,len);
            break;
        case 2:
            BubleSort(array,len);
            printf("冒泡排序结果:\n");
            print(array,len);
            break;
        case 3:
            InsertSort(array,len);
            printf("插入排序结果:\n");
            print(array,len);
        case 4:
            ShellSort(array,len);
            printf("希尔排序结果:\n");
            print(array,len);
        default:
            break;
        }
        system("pause");
        system("cls");
    }
}

/*
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
快速排序输入模板 
QuickSort(array,0,len-1);
            printf("Quick sorted array:\n");
            print(array,len);
            break; 
//选择排序
void SelectSort(int arr[],int n)
{
    int i,j,k,temp;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[k]) k = j;
        }
        if(k>i)
        {
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}
*/
