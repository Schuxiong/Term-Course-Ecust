#include <bits/stdc++.h>
int tag[105][105]={0}; //标记点是否被覆盖

int main()
{
	int n,m,r,sum=0;//n为网格图边长，m为探测器个数，r为探测半径 
	scanf("%d%d%d",&n,&m,&r);
	
	for(int i=1;i<=m;i++)
	{
	int x,y;
	scanf("%d%d",&x,&y);//一边输入一边计算 
	tag[x][y]=1;      //标记目标点 也就是探测器的位置 

	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	 { double r1=sqrt((x-i)*(x-i)+(y-j)*(y-j));
	  if (r1<=r)
	  tag[i][j]=1 ;    //逐个检查是不是在探测器范围之内 
   	 }
    }
    
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	  if(tag[i][j]=1)
	  sum++;  //若在范围内则加一 
	  
	printf("%d",sum);
	return 0;
 } 
