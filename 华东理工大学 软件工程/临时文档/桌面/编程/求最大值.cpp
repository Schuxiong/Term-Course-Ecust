#include <stdio.h>
#define N 10000
int main ()
{
	int a[N];
	int i,n;
	int max=-N;
	scanf ("%d",&n);//nΪ���ݸ���
	for  (i=0;i<n;i++)
	 scanf("%d",&a[i]);//ѭ���������� 
	for (i=0;i<n;i++)
	{

		if (a[i]>max)
		 max=a[i];
	 } 
	printf ("max=%d\n",max);
	return 0;
 } 
