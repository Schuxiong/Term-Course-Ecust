#include <bits/stdc++.h>
using namespace std; //��ʶ���ſ� 
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
		int p=a[i]; //�۸� 
		int num=0; //����ֵ 
		for (int j=1;j<=m;j++)
		if (a[j]>=p)
		num++;  //�ɹ����߼�һ 
		if(num>=n)
		num=n;
		if(p*num>maxx)
		{
			maxx=p*num;//�������ֵ 
			ans=p;
		}
	 } 
	 printf("%d %d",ans,maxx);
	 return 0;
}
