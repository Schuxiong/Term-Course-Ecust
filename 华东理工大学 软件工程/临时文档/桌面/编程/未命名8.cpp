#include <stdio.h>
#include <math.h>
int main ()
{
int a,b,c,d,e,f,i,n=0,x,y,sum=0,p=0;
scanf ("%d %d",&a,&b);
i=a;
for (;i>=a&&i<=b;i++)
{
	c=i;
	while (c!=0)
	{
		c/=10;
		n++;
	}
	for(x=n;x>=1;x--)
	{
		y=pow(10,x-1);
		d=(i/y)%10;
		e=pow(d,n);
		sum+=e;
		if(x==1&&sum==i)
		{
			printf("%d",sum);
			p++;
		}
		if(x==1)
		{
			sum+0
		}
	}
	n=0;
}
if(p==0)
{
	printf("none");
}
return 0;
 } 
