#include <stdio.h>
int main () 
{
	int a[100][100] ,b[100][100],c[100][100];
	int n,m,k,i,j,t;
	scanf ("%d%d%d",&n,&m,&k);
	
	for (i=0;i<n;i++)
	 for (j=0;j<m;j++)
	   scanf("%d",&a[i][j]);//�����һ������ 
	
	for (i=0;i<m;i++)
	 for (j=0;j<k;j++)
	   scanf("%d",&b[i][j]);//����ڶ�������
	
	for(i=0;i<n;i++) 
	 for (j=0;j<k;j++)
	  {
	  	c[i][j]=0;
	  	 for(t=0;t<m;t++)
	  	  c[i][j]+=a[i][t]*b[t][j];//���ж�Ӧ��� 
	  }
	
	for (i=0;i<n;i++)
	{
		for (j=0;j<k;j++)
		 printf("%d ",c[i][j]); //������󣬼ǵÿո�ͻ���
		printf ("\n") ;
	 } 
	return 0;
}
