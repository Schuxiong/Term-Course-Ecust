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
		a[i+1]=a[i];//���a[i]��insert��������ƶ�һλ 
		else break;//�������insert�������ѭ�� ��ʱa[i]��ֵС��insert 
	}

	a[i+1]=insert;//�ٰ�insert��ֵ��a[i+1] 
	for (i=0;i<N+1;i++)
	printf ("%d\n",a[i]);
	return 0;
}
