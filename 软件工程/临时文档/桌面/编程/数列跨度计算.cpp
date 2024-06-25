#include <stdio.h> 
int main ()
{
	int n,i,num[1000],min,max;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&num[i]);
	min=max=num[0];
	for(i=1;i<n;i++)
	{
		if(num[i]>max)
		   max=num[i];
		if(num[i]<min)
		   min=num[i];
	}
	printf("%d",max-min);
	return 0;
}
