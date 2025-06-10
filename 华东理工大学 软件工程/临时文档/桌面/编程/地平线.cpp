#include <stdio.h>
int main ()
{
	int n,i,j,sum=0;
	scanf ("%d",&n);
	int a[n];
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	for(i=1;i<=n;i++)
	  if (a[i]>a[i+1])
	   {
	   	if (a[i+1]<a[j+2])
	   	 sum+=1 ; 
	   	else
	   	 {
	   	 	a[i]=a[i+1];
	   	 	a[i+1]=a[i+2];
			}
	   }
	   printf ("%d",sum);
	   return 0;
 } 
