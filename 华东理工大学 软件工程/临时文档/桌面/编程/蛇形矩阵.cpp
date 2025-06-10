
#include<stdio.h>
	int main()
	{
	int n,m; //n行n列的蛇形方阵 
	scanf("%d",&n); 
	m=n;
	int dx[]={-1,0,1,0};	
	int dy[]={0,1,0,-1};  //dx和dy数组用于调整方向
	int g[110][110] = {0}; //初始化数组元素全为0   
	int x=0,y=0,d=1;    
	
	for(int i=1;i<=m*n;i++)
	{
	
		g[x][y]=i; 
		int a=x+dx[d]; //开始时先向右移，以从d=1开始 即 
		int b=y+dy[d];  //a和b记录要移动到的位置
		if(a<0||a>=m||b<0||b>=n||g[a][b]) //边界处理，如果满足这四种条件中的一种，即越界，需要改变方向。
		{
			d=(d+1)%4; //顺时针改变方向操作
			a=x+dx[d]; 
			b=y+dy[d];
		}
		x=a;
		y=b;
	}
	
	for(int i=0;i<m;i++)  //输出蛇形矩阵
	{  for(int j=0;j<n;j++)
			printf("%3d",g[i][j]);
			printf("\n");
	}
}

