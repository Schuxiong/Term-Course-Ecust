#include<bits/stdc++.h>
using namespace std;
struct eee
{
	int Chinese,sum,Math,English;
	char name[50];
}x[1001];

int main ()
{
	int n ;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%d%d%d",x[i].name,&x[i].Chinese,&x[i].Math,&x[i].English);
		x[i].sum=x[i].Chinese+x[i].Math+x[i].English;//计算总分 
	}
	
	for (int i=1;i<n ;++i)//从2开始 
	 for (int j=i+1;j<n;j++)//从1开始 
	  {
	  	if(x[i].sum<x[j].sum)
	  	{
	  		swap(x[i].Chinese,x[j].Chinese);//数值交换函数 
	  		swap(x[i].Math,x[j].Math);
	  		swap(x[i].English,x[j].English);
	  		swap(x[i].name,x[j].name);
	  		swap(x[i].sum,x[j].sum);
		  }
	  }
	  printf("%s %d %d %d\n",x[1].name,x[1].Chinese,x[1].Math,x[1].English);
	  return 0; 
}
