#include<bits/stdc++.h>
char b[30];  //字母用数组输入表示颜色 、

int main () 
{
	int n,ans=0; //n为人数 ans为结果
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("\n");
		scanf("%c",&b[i]);
	 } 
	 for(int i=1;i<=n;i++)
	  if(b[i]!=b[i+1])
	   ans++;
	   
	   printf("%d",ans+1);
	   return 0;
}
