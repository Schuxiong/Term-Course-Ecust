#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
void Sort(int a[],int n)
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

 int main ()
 {
 	int arr[MAX];
 	int N=0;
 	int n=0,i=0;
 	int k;
 	for (;n!=-1;)
 	{
 		scanf("%d",&n);
 		arr[i]=n;i++;N++;
	 }
 	Sort(arr,N);
    scanf("%d",&k);
	 printf("%d",arr[N-k]);
           
 }
