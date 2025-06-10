#include <stdio.h>
#include <string.h>
int main()
{
  int n;
   scanf("%d",&n);
   long a[n];
   for (int i=0;i<n;i++)
    scanf("%ld",&a[i]);
    long maxin=a[1],max=a[n-1];
    for (int i=0;i<n;i++)
	{
    if(a[i]>max)
	max=a[i];
    if(a[i] <=max && a[i]>maxin)
    maxin=a[i];
    }
printf("%ld %ld\n",max, maxin);
}
