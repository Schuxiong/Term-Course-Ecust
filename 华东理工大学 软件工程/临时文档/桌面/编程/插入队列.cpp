#include <stdio.h>
#define N 4
int main ()
{
	int a[N+1],i,insert;

	for (i=0;i<N;i++)
	  scanf ("%d",&a[i]);
	scanf("%d",&insert);

	for (i=N-1;i>=0;i--)
	{
		if (a[i]>insert)
		a[i+1]=a[i];//如果a[i]比insert大则向后移动一位 
		else break;//如果不比insert大则结束循环 此时a[i]的值小于insert 
	}

	a[i+1]=insert;//再把insert赋值给a[i+1] 
	for (i=0;i<N+1;i++)
	printf ("%d\n",a[i]);
	return 0;
}
