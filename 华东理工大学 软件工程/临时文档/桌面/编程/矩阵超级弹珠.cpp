#include <bits/stdc++.h> //���ܺ�����
int a[1001][1001];
int main ()
{
	int n;
	
	scanf ("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf ("%d",&a[i][j]); 
			
	//���������ѭ�� 
	
	int ans=-1;
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==0) //�ж����λ���Ƿ��е��� 
			{
				int x=0;
				for (int k=1;k<=n;k++)
				x+=a[i][k]+a[k][j];   //�����������е��˵Ļ���֮��
				if (ans<x)
				ans=x;//ѭ���Ƚ� ���ϴ�ֵ��ֵ��ans 
			 } 
	
	if (ans==-1)
		printf("Bad Game!\n");//������Ǹ�ֵ ���ʾû������֮�� 
	else
	   printf("%d\n",ans);	 
 } 

