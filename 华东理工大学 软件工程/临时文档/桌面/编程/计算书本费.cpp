#include <stdio.h> 
int main()
{
	double price[10]={28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
	double sum=0;
	int i,n;
	for (i=0;i<10;i++)
	{
		scanf("%d",&n);
		sum+=n*price[i];
	}
	printf("%.1lf",sum);
	return 0;
}
