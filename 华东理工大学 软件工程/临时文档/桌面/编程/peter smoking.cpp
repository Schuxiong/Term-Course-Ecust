#include <stdio.h>
int main ()
{
	int k,n;
	scanf("%d %d",&n,&k);
	int ans=0;
	while (1)
	{
		if(n/k!=0)
		{
			ans+=(n/k)*k;
			n=n/k+n%k;
		}
		else
		 {
		 	ans+=1;
			 break;
		 }
		
	}
	printf("%d",ans);
}
