#include<stdio.h>
int main ()
{
	int a[100][100],b[100][100],sum[100][100];
	int n,m,j,i;
	scanf ("%d%d",&n,&m);
	
	for (i=0;i<n;i++)
	 for (j=0;j<m;j++)
	  scanf ("%d",&a[i][j]);//扫描第一个矩阵 
	
	for (i=0;i<n;i++)
	 for (j=0;j<m;j++)
	 {
	  scanf ("%d",&b[i][j]);//扫描第二个矩阵 
	  sum[i][j]=a[i][j]+b[i][j];
     }
    
	for (i=0;i<n;i++)
    {
    	for (j=0;j<m;j++)
    	 printf ("%d ",sum[i][j]);//通过循环输出一行
		printf ("\n");//接着输出下一行 
	}
	return 0; 	
}
