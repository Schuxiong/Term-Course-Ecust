#include <bits/stdc++.h>
using namespace std; //标识符号库 
int a [100002] ; 
int main ()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	scanf ("%d",&a[i]);
	
	int ans=0,maxx=0;
	for(int i=1;i<=m;i++)
	{
		int p=a[i]; //价格 
		int num=0; //赋初值 
		for (int j=1;j<=m;j++)
		if (a[j]>=p)
		num++;  //可购买者加一 
		if(num>=n)
		num=n;
		if(p*num>maxx)
		{
			maxx=p*num;//计算最大值 
			ans=p;
		}
	 } 
	 printf("%d %d",ans,maxx);
	 return 0;
}
