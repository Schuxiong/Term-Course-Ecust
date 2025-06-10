#include <stdio.h>
int main () 
{
	int a[100][100] ,b[100][100],c[100][100];
	int n,m,k,i,j,t;
	scanf ("%d%d%d",&n,&m,&k);
	
	for (i=0;i<n;i++)
	 for (j=0;j<m;j++)
	   scanf("%d",&a[i][j]);//输入第一个矩阵 
	
	for (i=0;i<m;i++)
	 for (j=0;j<k;j++)
	   scanf("%d",&b[i][j]);//输入第二个矩阵
	
	for(i=0;i<n;i++) 
	 for (j=0;j<k;j++)
	  {
	  	c[i][j]=0;
	  	 for(t=0;t<m;t++)
	  	  c[i][j]+=a[i][t]*b[t][j];//行列对应相乘 
	  }
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<k;j++)
		 printf("%d ",c[i][j]); //输出矩阵，记得空格和换行
		printf ("\n") ;
	 } 
	return 0;
}
