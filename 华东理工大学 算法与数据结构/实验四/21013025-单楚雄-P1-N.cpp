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

//������
void HeapSort(int A[], int N)
{
	int i,temp;
	//��������
	for (i = N / 2 - 1; i >= 0; i--) PercDown(A, i, N);
	//����Ѷ�
	for (i = N - 1; i >= 0; i--)
	{
		Swap(&A[0],&A[i]);
		PercDown(A,0,i);
	}
}
//ð������
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


// ϣ������
void ShellSort(int A[], int N)
{
	int Si, D, P, i;
	int Tmp;
		//ϣ������ ��Sedgewick�������У�����ֻ������������  
		int Sedgewick[] = { 929,505,209,109,41,19,5,1,0 };

	for (Si = 0; Sedgewick[Si] >= N; Si++);//��ʼ��Sedgewick�������ܳ������������г���

	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
		for (P = D; P < N; P++)
		{
			Tmp = A[P];
			for (i =P; i >= D && A[i - D] > Tmp; i -=D)
				A[i] = A[i - D];
			A[i] = Tmp;
		}
}

//��������
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
        printf("ѡ�����򷽷�:\n");//��ʾ�˵�
        printf("\t0 �˳�\n\t1 ������\n\t2 ð������\n\t3 ֱ�Ӳ�������\n\t4 ϣ������\n��ѡ��>>");
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
            printf("��������:\n");
            print(array,len);
            break;
        case 2:
            BubleSort(array,len);
            printf("ð��������:\n");
            print(array,len);
            break;
        case 3:
            InsertSort(array,len);
            printf("����������:\n");
            print(array,len);
        case 4:
            ShellSort(array,len);
            printf("ϣ��������:\n");
            print(array,len);
        default:
            break;
        }
        system("pause");
        system("cls");
    }
}

/*
//��������
void QuickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int i = left, j = right, x = a[left];
        while (i < j)
        {
            while(i < j && a[j] >= x) // ���������ҵ�һ��С��x����
                j--;  
            if(i < j) 
                a[i++] = a[j];

            while(i < j && a[i] < x) // ���������ҵ�һ�����ڵ���x����
                i++;  
            if(i < j) 
                a[j--] = a[i];
        }
        a[i] = x;
        QuickSort(a, left, i - 1); // �ݹ���� 
        QuickSort(a, i + 1, right);
    }
}
������������ģ�� 
QuickSort(array,0,len-1);
            printf("Quick sorted array:\n");
            print(array,len);
            break; 
//ѡ������
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
