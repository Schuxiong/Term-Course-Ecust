#include <stdio.h>
#define N 5
int main()
{
	int x[N+1][N+1],i,j,temp,m,n;
	for(i=1;i<=N;i++)
	for(j=1;j<=N;j++)
	  scanf("%d",&x[i][j]);
	  scanf("%d%d",&m,&n);
	for (j=1;j<=N;j++)
	{
		temp=x[m][j];
		x[m][j]=x[n][j];
		x[n][j]=temp;
	}
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=N;j++)
		printf("%d",x[i][j]);
		printf("\n");
	 } 
	return 0;
}
