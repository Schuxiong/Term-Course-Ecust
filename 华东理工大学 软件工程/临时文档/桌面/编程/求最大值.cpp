#include <stdio.h>
#define N 10000
int main ()
{
	int a[N];
	int i,n;
	int max=-N;
	scanf ("%d",&n);//n为数据个数
	for  (i=0;i<n;i++)
	 scanf("%d",&a[i]);//循环输入数据 
	for (i=0;i<n;i++)
	{

		if (a[i]>max)
		 max=a[i];
	 } 
	printf ("max=%d\n",max);
	return 0;
 } 
