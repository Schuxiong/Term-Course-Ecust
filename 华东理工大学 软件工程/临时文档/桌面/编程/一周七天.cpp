#include <stdio.h>
int main ()
{
	int a,b;
	int i,t=8,ans=0;
	for(i=0;i<7;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if (a+b > t)
		t=a+b,ans=i+1;
	}
	printf("%d",ans);
	return 0;
}
