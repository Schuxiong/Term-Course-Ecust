#include<stdio.h>
int main ()
{
	int a[100][100],b[100][100],sum[100][100];
	int n,m,j,i;
	scanf ("%d%d",&n,&m);
	
	for (i=0;i<n;i++)
	 for (j=0;j<m;j++)
	  scanf ("%d",&a[i][j]);//ɨ���һ������ 
	
	for (i=0;i<n;i++)
	 for (j=0;j<m;j++)
	 {
	  scanf ("%d",&b[i][j]);//ɨ��ڶ������� 
	  sum[i][j]=a[i][j]+b[i][j];
     }
    
	for (i=0;i<n;i++)
    {
    	for (j=0;j<m;j++)
    	 printf ("%d ",sum[i][j]);//ͨ��ѭ�����һ��
		printf ("\n");//���������һ�� 
	}
	return 0; 	
}
