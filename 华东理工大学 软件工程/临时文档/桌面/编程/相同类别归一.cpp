#include<bits/stdc++.h>
char b[30];  //��ĸ�����������ʾ��ɫ ��

int main () 
{
	int n,ans=0; //nΪ���� ansΪ���
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
