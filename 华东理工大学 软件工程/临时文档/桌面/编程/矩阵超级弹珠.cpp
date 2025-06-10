#include <bits/stdc++.h> //万能函数库
int a[1001][1001];
int main ()
{
	int n;
	
	scanf ("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf ("%d",&a[i][j]); 
			
	//输入矩阵常用循环 
	
	int ans=-1;
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==0) //判断这个位置是否有敌人 
			{
				int x=0;
				for (int k=1;k<=n;k++)
				x+=a[i][k]+a[k][j];   //计算这行这列敌人的积分之和
				if (ans<x)
				ans=x;//循环比较 最后较大值赋值给ans 
			 } 
	
	if (ans==-1)
		printf("Bad Game!\n");//如果还是赋值 则表示没有容身之地 
	else
	   printf("%d\n",ans);	 
 } 

